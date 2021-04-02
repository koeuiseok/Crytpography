#include "src/lea.h"
#include "src/lea_locl.h"
#include "benchmark.h"
#include "lea_benchmark.h"
#include "lea_vs.h"
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
__int64 cpucycle(void) { return __rdtsc(); }
/*
__int64 cpucycle(void) { return __rdtsc(); }

int main() {
	LEA_CMAC_CTX cmac_ctx;

	unsigned long long cycles, cycles1, cycles2, cycle = 0;
	unsigned char message[3] = { 0x61,0x62,0x63 };
	unsigned int msg_len = 3;
	unsigned char mk[3] = { 0x61,0x62,0x63 };
	unsigned int mk_len = 3;
	unsigned char cmac[16] = { 0, };
	unsigned int Tlen = 128;
	int uPlaintext = 3;

	cycles1 = cpucycle();
	for (int i = 0; i < 100000; i++) {
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
	}
	
	cycles2 = cpucycle();
	cycles = cycles2 - cycles1;
	printf("cycles : %10lld", cycles / 100000);
	printf("\n");
	return 0;
}
*/


void LEA_CMAC_1(unsigned char* msg,unsigned char* Key,unsigned int msg_len,unsigned int key_len,unsigned char* cmac, unsigned int Tlen) {
	LEA_KEY* RK = { 0, };
	lea_set_key(&RK, Key, key_len);
	if (msg_len == 0) {
		msg[0] = 1;
	}
	unsigned char K1[16] = { 0, };
	unsigned char K2[16] = { 0, };
	unsigned char X[16] = { 0, };
	unsigned int cnt=0, last_len = 0;
	last_len = msg_len;
	while (last_len > 16) {
		last_len = last_len >> 7;
		cnt++;
	}
	unsigned char* new_Msg = (unsigned char*)calloc((cnt + 1) * 16, sizeof(unsigned char));
	memcpy(new_Msg, msg, msg_len);

	if (last_len == 16 ){
		for (int i = 0; i < 16; i++) {
			new_Msg[cnt*16+i] ^= K1[i];
		}
	}
	else {
		for (int i = 0; i < last_len; i++) {
			new_Msg[cnt * 16 + i] = K2[i];
		}
		new_Msg[cnt * 16 + last_len ] = 1;

		memset(new_Msg[cnt * 16], 0, 16 - last_len);
	}

	unsigned char Y[16] = { 0, };
	for (int i = 0; i <= cnt; i++) {
		for (int j = 0; j < 16; j++) {
			X[j] = Y[j]^new_Msg[16*i+j];
		}
		lea_ecb_enc(Y, X, 16,&RK );
	}

	for (int w = 0; w < 16; w++) {
		printf("%02x", Y[w]);
	}
}


static void lea_cmac_subkey(unsigned char* new_key, 
	const unsigned char* old_key, unsigned int key_len)
{
	unsigned int i;
	for (i = 0; i < key_len-1; i++) {
		new_key[i] = old_key[i] << 1;
		new_key[i] += old_key[i + 1] >> 7;
	}
	new_key[key_len-1] = old_key[key_len-1]<<1;

	if (old_key[0] >> 7) {
		new_key[key_len-1] ^= 0x87;
	}

}

void CMAC_INIT(LEA_CMAC_CTX* ctx, const unsigned char* mk, int mk_len)
{
	unsigned char zero[16] = { 0, };


	lea_set_key(&ctx->key, mk, mk_len);

	lea_encrypt(zero, zero, &ctx->key);
	lea_cmac_subkey(ctx->k1, zero, 16);
	lea_cmac_subkey(ctx->k2, ctx->k1, 16);

	memset(ctx->tbl, 0, 16);
	memset(ctx->last_block, 0, 16);

	ctx->nlast_block = 0;
}



void CMAC_process(LEA_CMAC_CTX* ctx, const unsigned char* data, int data_len)
{

	for (; data_len > 16; data_len -= 0x10, data += 0x10)
	{
		XOR8x16(ctx->tbl, ctx->tbl, data);

		lea_encrypt(ctx->tbl, ctx->tbl, &ctx->key);
	}

	memcpy(ctx->last_block, data, data_len);

	ctx->nlast_block = data_len;
}

void CMAC_close(LEA_CMAC_CTX* ctx, unsigned char* cmac, int cmac_len)
{

	if (ctx->nlast_block != 16)
	{
		ctx->last_block[ctx->nlast_block] = 0x80;
		memset(ctx->last_block + ctx->nlast_block + 1, 0, 15 - ctx->nlast_block);

		for (ctx->nlast_block; ctx->nlast_block >= 0; ctx->nlast_block--)
			ctx->tbl[ctx->nlast_block] ^= ctx->last_block[ctx->nlast_block];

		XOR8x16(ctx->tbl, ctx->tbl, ctx->k2);
	}
	else
	{
		XOR8x16(ctx->tbl, ctx->tbl, ctx->last_block);
		XOR8x16(ctx->tbl, ctx->tbl, ctx->k1);
	}

	lea_encrypt(ctx->tbl, ctx->tbl, &ctx->key);

	for (cmac_len--; cmac_len >= 0; cmac_len--)
		cmac[cmac_len] = ctx->tbl[cmac_len];

	ctx->nlast_block = 0;
	memset(ctx->last_block, 0, 16);
	memset(ctx->tbl, 0, 16);
}


int main() {
	LEA_CMAC_CTX cmac_ctx;
	unsigned char message[3] = { 0x12,0x12,0x14};
	unsigned int msg_len = 3;
	unsigned char mk[16] = { 0x29, 0x23, 0xBE, 0x84, 0xE1, 0x6C, 0xD6,0xAE,0x52,0x90,0x49,0xF1,0xF1,0xBB,0xE9,0xEB };
	unsigned int mk_len = 16;
	unsigned char cmac[16] = { 0, };
	unsigned int Tlen = 128;
	int uPlaintext = 3;
	unsigned long long cycles, cycles1, cycles2, cycle = 0;
	cycles1 = cpucycle();
	for (int i = 0; i < 100000; i++) {
		CMAC_INIT(&cmac_ctx, mk, mk_len);
		CMAC_process(&cmac_ctx, message, msg_len);
		CMAC_close(&cmac_ctx, cmac, Tlen >> 3);
	}

	cycles2 = cpucycle();
	cycles = cycles2 - cycles1;
	printf("cycles : %10lld", cycles / 100000);
	printf("\n");

	return 0;

}





/*
int main() {                 // CMAC_Gent_LEA128
	LEA_CMAC_CTX cmac_ctx;
	FILE* req, *rsp;
	req = fopen("C:\\Users\\82109\\Desktop\\고의석\\암호최적화\\3주차 CMAC_LEA HMAC_SHA512\\LEA_C_Standalone_src\\CMACGenLEA128.REQ","rb");
	rsp = fopen("C:\\Users\\82109\\Desktop\\고의석\\암호최적화\\3주차 CMAC_LEA HMAC_SHA512\\LEA_C_Standalone_src\\CMACGenLEA128.RSP", "w");
	if (rsp == NULL) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == NULL) {
		printf("req open 실패!!\n");
		return 1;
	}
	unsigned char mk[16] = { 0, };
	unsigned char tmp[100];
	unsigned int RR=0;
	unsigned char R2 = 0;
	unsigned char* T = calloc(0, sizeof(unsigned char));
	unsigned char* message = calloc(0, sizeof(unsigned char));
	unsigned char* cmac = calloc(0, sizeof(unsigned char));
	unsigned int Tlen = 0, msg_len = 0;
	
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);

		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen>>3);
		printf("\n");
		fprintf(rsp, "\nT = ");

		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp,"%02X", cmac[w]);
		}
	}
	//0~4 : 0
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 6;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen>>3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//5~9 : 6
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 18;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//10~14 : 18
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 185;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//15 : 185
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);

		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");

		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//20~24 : 0
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 28;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//25~29 : 28
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 52;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//30~34 : 52
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 79;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//35~39 : 79
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 190;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//40~44 : 190
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);

		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");

		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//45~49 : 0
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 46;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//50~54 : 46
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 88;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//55~59 : 88
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 147;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//60~64 : 147
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 162;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//65~69 : 162
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);

		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");

		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//70~74 : 0
	for (int j = 0; j < 5; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 112;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//75~79 : 112
	for (int j = 0; j < 10; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 66;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen >> 3);
		printf("\n");
		fprintf(rsp, "\nT = ");
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fprintf(rsp, "%02X", cmac[w]);
		}
	}
	//75~79 : 112

	fclose(rsp);
	fclose(req);
	return 0;
}
*/
//GEN

/*

int main() {                 // CMAC_Ver_LEA128
	LEA_CMAC_CTX cmac_ctx;
	FILE* req, *rsp;
	req = fopen("C:\\Users\\82109\\Desktop\\고의석\\암호최적화\\3주차 CMAC_LEA HMAC_SHA512\\LEA_C_Standalone_src\\CMACVerLEA128.REQ","rb");
	rsp = fopen("C:\\Users\\82109\\Desktop\\고의석\\암호최적화\\3주차 CMAC_LEA HMAC_SHA512\\LEA_C_Standalone_src\\CMACVerLEA128.RSP", "w");
	if (rsp == NULL) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == NULL) {
		printf("req open 실패!!\n");
		return 1;
	}
	unsigned char mk[16] = { 0, };
	unsigned int key_len = 0;
	unsigned char tmp[100];
	unsigned int RR=0;
	unsigned char R2 = 0;
	unsigned char* T = calloc(0, sizeof(unsigned char));
	unsigned char* message = calloc(0, sizeof(unsigned char));
	unsigned char* cmac = calloc(0, sizeof(unsigned char));
	unsigned int Tlen = 0, msg_len = 0;

	for (int j = 0; j < 10; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);

		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen);
		printf("\n");
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		T = realloc(T, Tlen * sizeof(unsigned char));
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			T[w] = R2;
		}
		for (int w = 0; w < Tlen >> 3; w++) {
			if (T[w] != cmac[w]) {
				fprintf(rsp, "\nINVALID\n");
				break;
			}
			else if (w == (Tlen >> 3)-1) {
				fprintf(rsp, "\nVALID\n");
			}
		}
	}
	//0~9까지 M 길이가 0일때
	for (int j = 0; j < 10; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 32;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen);
		printf("\n");
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		T = realloc(T, Tlen * sizeof(unsigned char));
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			T[w] = R2;
		}
		for (int w = 0; w < Tlen >> 3; w++) {
			if (T[w] != cmac[w]) {
				fprintf(rsp, "\nINVALID\n");
				break;
			}
			else if (w == (Tlen >> 3) - 1) {
				fprintf(rsp, "\nVALID\n");
			}
		}
	}
	//10~19까지 M 길이가 32일때
	for (int j = 0; j < 10; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 64;
		fscanf(req, "%s = ", tmp);
		message = (unsigned char*)realloc(message,(msg_len)*sizeof(unsigned char));
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen);
		printf("\n");
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		T = realloc(T, Tlen * sizeof(unsigned char));
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			T[w] = R2;
		}
		for (int w = 0; w < Tlen >> 3; w++) {
			if (T[w] != cmac[w]) {
				fprintf(rsp, "\nINVALID\n");
				break;
			}
			else if (w == (Tlen >> 3) - 1) {
				fprintf(rsp, "\nVALID\n");
			}
		}
	}
	//20~29까지 M 길이가 64일때
	for (int j = 0; j < 10; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 10;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen);
		printf("\n");
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		T = realloc(T, Tlen * sizeof(unsigned char));
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			T[w] = R2;
		}
		for (int w = 0; w < Tlen >> 3; w++) {
			if (T[w] != cmac[w]) {
				fprintf(rsp, "\nINVALID\n");
				break;
			}
			else if (w == (Tlen >> 3) - 1) {
				fprintf(rsp, "\nVALID\n");
			}
		}
	}
	//30~39까지 M 길이가 10일때
	for (int j = 0; j < 10; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 20;
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen);
		printf("\n");
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		T = realloc(T, Tlen * sizeof(unsigned char));
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			T[w] = R2;
		}
		for (int w = 0; w < Tlen >> 3; w++) {
			if (T[w] != cmac[w]) {
				fprintf(rsp, "\nINVALID\n");
				break;
			}
			else if (w == (Tlen >> 3) - 1) {
				fprintf(rsp, "\nVALID\n");
			}
		}
	}
	//40~49까지 M 길이가 20일때
	for (int j = 0; j < 10; j++) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		printf("%d", RR);

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			mk[i] = R2;
			printf("%02X", R2);
		}
		msg_len = 65;
		fscanf(req, "%s = ", tmp);
		message = (unsigned char*)realloc(message, (msg_len) * sizeof(unsigned char));
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < msg_len; i++) {
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			message[i] = R2;
			printf("%02X", R2);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		Tlen = RR;

		unsigned int mk_len = 16;
		lea_cmac_init(&cmac_ctx, mk, mk_len);
		lea_cmac_update(&cmac_ctx, message, msg_len);
		lea_cmac_final(&cmac_ctx, cmac, Tlen);
		printf("\n");
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		T = realloc(T, Tlen * sizeof(unsigned char));
		for (int w = 0; w < Tlen >> 3; w++) {
			printf("%02x", cmac[w]);
			fscanf(req, "%02X", &R2);
			fprintf(rsp, "%02X", R2);
			T[w] = R2;
		}
		for (int w = 0; w < Tlen >> 3; w++) {
			if (T[w] != cmac[w]) {
				fprintf(rsp, "\nINVALID\n");
				break;
			}
			else if (w == (Tlen >> 3) - 1) {
				fprintf(rsp, "\nVALID\n");
			}
		}
	}
	//50~59까지 M 길이가 65일때

	fclose(rsp);
	fclose(req);
	return 0;
}
*

/*
int main(void)
{
	int ret;
	printf("SIMD: %s\n", get_simd_type());
	if (ret = lea_cmac_g_test())		printf("LEA CMAC FAIL(%d)\n", ret);

	lea_cmac_benchmark();
	
	if(ret = lea_mmt_ecb_test())	printf("LEA ECB FAIL(%d)\n", ret);
	if(ret = lea_mmt_cbc_test())	printf("LEA CBC FAIL(%d)\n", ret);
	if(ret = lea_mmt_ctr_test())	printf("LEA CTR FAIL(%d)\n", ret);
	if(ret = lea_mmt_ofb_test())	printf("LEA OFB FAIL(%d)\n", ret);
	if(ret = lea_mmt_cfb_test())	printf("LEA CFB FAIL(%d)\n", ret);
	if(ret = lea_ccm_ge_test())		printf("LEA CCM FAIL(%d)\n", ret);
	if(ret = lea_gcm_ae_test())		printf("LEA GCM FAIL(%d)\n", ret);
	
	lea_key_benchmark();
	lea_ecb_benchmark();
	lea_cbc_benchmark();
	lea_ctr_benchmark();
	lea_ofb_benchmark();
	lea_cfb_benchmark();
	lea_ccm_benchmark();
	lea_gcm_benchmark();
	
	return 0;
}
*/
//Ver