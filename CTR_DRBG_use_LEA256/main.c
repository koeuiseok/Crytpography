/******************************************************************************
* what is this code? : It makes test response file about request file drbg
* base crypto :  LEA128-CTR(operation mode)
* support function : DRBG (use/no df and use/no pr)
* 
*
* If you want to use this code, you will download kisa LEA code, first.
*
* If you want to know more imformation, you will contact me : y1201k@kookmin.ac.kr
*
******************************************************************************/

#include "src/lea.h"
#include "src/lea_locl.h"
#include "benchmark.h"
#include "lea_benchmark.h"
#include "lea_vs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define speed_test   // you can use speed test 
// #define no_df_use_pr // you can use no df use pr test

#define blocklen_byte 16
#define blocklen 128
#define keylen_byte 32
#define keylen 256
#define len_seed 3
#define seedlen 48

unsigned char lea256_CBC_key[32] = { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,
0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,0x12,
0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f };

typedef struct ctr_drbg_ctx {
	unsigned char V[blocklen_byte];
	unsigned char key[keylen_byte];
	unsigned int reseed_counter;

	unsigned int prediction_resistance_flag;
}CTR_DRBG_CTX;

void df(unsigned char* input, unsigned int input_len,
	unsigned char* output, unsigned int output_len, const LEA_KEY* key)
{

	unsigned char block_input[16] = { 0x00, };
	unsigned char block_output[16] = { 0x00, };

	unsigned char C[16] = { 0x00, };
	unsigned char L[4] = { 0x00, };
	unsigned char N[4] = { 0x00, };
	L[0] = input_len >> 24;
	L[1] = input_len >> 16;
	L[2] = input_len >> 8;
	L[3] = input_len;   

	N[0] = output_len >> 24;
	N[1] = output_len >> 16;
	N[2] = output_len >> 8;
	N[3] = output_len; 

	unsigned int S_len = 0;
	S_len = 8 + input_len + 1; 
	unsigned int padd_len = S_len % 16;
	if (padd_len != 0) {
		padd_len = 16 - padd_len; 
	}
	S_len += padd_len;
	unsigned int i = 0;
	unsigned char new_key[keylen_byte] = { 0x00, };
	unsigned char V[blocklen_byte] = { 0x00, };

	unsigned char* data = (unsigned char*)calloc(S_len, sizeof(unsigned char));
	memcpy(data, L, 4);
	memcpy(data+4,N,4);
	memcpy(data + 8, input, input_len);
	data[8 + input_len] = 0x80;
	for (unsigned char w = 0x00; w < len_seed; w++) {
		lea_encrypt(block_output, C, key);
		unsigned char cnt = S_len / 16;
		for (i = 0; i < cnt; i++)
		{
			memcpy(block_input, data + (i * blocklen_byte), blocklen_byte);
			for (int j = 0; j < blocklen_byte; j++)
				block_input[j] ^= block_output[j];
			lea_encrypt(block_output, block_input, key);
		}
		if (w == 0x00)
			memcpy(new_key, block_output, blocklen_byte);
		else if (w == 0x01)
			memcpy(new_key + blocklen_byte, block_output, blocklen_byte);
		else if (w == 0x02)
			memcpy(V, block_output, blocklen_byte);
		C[3]++;
	}

	memcpy(block_output, V, blocklen_byte);
	LEA_KEY drbg_key = { {0x00,},0x00 };
	lea_set_key(&drbg_key, new_key, 32);
	for (unsigned char cnt = 0; cnt < len_seed; cnt++) {
		lea_encrypt(block_output, block_output, &drbg_key);
		memcpy(output + (blocklen_byte * cnt), block_output, blocklen_byte);
	}
	free(data);
}

void CTR_add1(unsigned char* input, unsigned int len) {
	unsigned int i=0;
	unsigned char carry = 1, carry0 = 0;
	for (i=len-1; i >0; i--) {
		carry0 = (input[i] + carry) >> 8;
		input[i] +=  carry;
		carry = carry0;
	}
	input[0] += carry;
}

int CTR_add(unsigned char* input, unsigned int len) {
	unsigned int i = 0;
	unsigned char carry = 1;
	for (i = len-1; i >0; i--) {
		if (carry == 1) {
			carry = (input[i] + 1) >> 8;
			input[i] += 1;
		}
		else
			return 0;
	}
	input[0] +=carry;
	return 0;
}

void update(CTR_DRBG_CTX* drbg_ctx, unsigned char* input_data, 
	unsigned char* output)
{
	LEA_KEY drbg_key = { {0x00,},0x00, };
	lea_set_key(&drbg_key, drbg_ctx->key, keylen_byte);
	unsigned char output_block[blocklen_byte] = { 0x00, };
	unsigned char block_input[seedlen] = { 0x00, };
	
	for (int i = 0; i < len_seed; i++) {
		CTR_add(drbg_ctx->V, blocklen_byte);
		lea_encrypt(output_block, drbg_ctx->V, &drbg_key);
		memcpy(output + (i * blocklen_byte), output_block, blocklen_byte);
	}
	for (int i = 0; i < seedlen; i++) {
		output[i] ^= input_data[i];
	}
}

void generator(CTR_DRBG_CTX* drbg_ctx, unsigned char* output,unsigned int outlen)
{
	LEA_KEY drbg_key = { {0x00,},0x00, };
	lea_set_key(&drbg_key, drbg_ctx->key, keylen_byte);
	unsigned char output_block[blocklen_byte] = { 0x00, };
	unsigned int cnt = outlen / 16;
	unsigned char* tmp = (unsigned char*)calloc(blocklen_byte * cnt, sizeof(unsigned char));

	for (int i = 0; i < cnt; i++) {
		CTR_add(drbg_ctx->V, blocklen_byte);
		lea_encrypt(output_block, drbg_ctx->V, &drbg_key);
		memcpy(tmp + (i * blocklen_byte), output_block, blocklen_byte);
	}

	for (unsigned int i = 0; i < outlen; i++) {
		memcpy(output, tmp, outlen);
	}
	free(tmp);
}


void Instante_fnc_use_df(CTR_DRBG_CTX* drbg_ctx, unsigned char* entropy, unsigned int entropy_len, unsigned char* nonce
	,unsigned int nonce_len,unsigned char* personal_string, unsigned int per_len )
{
	LEA_KEY key = { {0x00,},0x00, };
	lea_set_key(&key, lea256_CBC_key, 32);
	unsigned int input_len = entropy_len + nonce_len + per_len;
	unsigned char* input_data = (unsigned char*)calloc(input_len, sizeof(unsigned char));
	unsigned char seed[seedlen] = { 0x00, };
	unsigned char new_seed[seedlen] = { 0x00, };
	unsigned char block_output[blocklen_byte] = { 0x00, };
	memcpy(input_data, entropy, entropy_len);
	memcpy(input_data+ entropy_len, nonce,nonce_len );
	if (per_len != 0) {
		memcpy(input_data + entropy_len + nonce_len, personal_string, per_len);
	}

	df(input_data, input_len, seed, seedlen, &key);
	memset(drbg_ctx->key, 0, keylen_byte);
	memset(drbg_ctx->V, 0, blocklen_byte);
	update(drbg_ctx, seed, new_seed);
	memcpy(drbg_ctx->key, new_seed, keylen_byte);
	memcpy(drbg_ctx->V, new_seed+keylen_byte,blocklen_byte);
	
	drbg_ctx->reseed_counter = 1;
	free(input_data);
}

void Instante_fnc_no_df(CTR_DRBG_CTX* drbg_ctx, unsigned char* entropy, unsigned int entropy_len, unsigned char* nonce
	, unsigned int nonce_len, unsigned char* personal_string, unsigned int per_len)
{
	LEA_KEY key = { {0x00,},0x00, };
	lea_set_key(&key, lea256_CBC_key, 32);
	unsigned char seed[seedlen] = { 0x00, };
	unsigned char new_seed[seedlen] = { 0x00, };
	unsigned char block_output[blocklen_byte] = { 0x00, };

	memcpy(seed, personal_string, per_len);
	for (unsigned int i = 0; i < seedlen; i++) {
		seed[i] ^= entropy[i];
	}

	memset(drbg_ctx->key, 0, keylen_byte);
	memset(drbg_ctx->V, 0, blocklen_byte);
	update(drbg_ctx, seed, new_seed);
	memcpy(drbg_ctx->key, new_seed, keylen_byte);
	memcpy(drbg_ctx->V, new_seed + keylen_byte, blocklen_byte);

	drbg_ctx->reseed_counter = 1;
}


void reseed_fnc(CTR_DRBG_CTX* drbg_ctx, unsigned char* entropy,
	unsigned int entropy_len, unsigned char* add_input, unsigned int add_len, LEA_KEY* key)
{
	unsigned int seed_material_len = 0;
	seed_material_len = entropy_len + add_len;
	unsigned char* seed_material = NULL;
	seed_material = (unsigned char*)calloc(seed_material_len, sizeof(unsigned char));
	memcpy(seed_material, entropy, entropy_len);
	if (add_len != 0) {
		memcpy(seed_material + entropy_len, add_input, add_len);
	}
	unsigned char out_df[seedlen] = { 0x00, };
	df(seed_material, seed_material_len, out_df, seedlen, key);
	unsigned char new_seed[seedlen] = { 0x00, };
	update(drbg_ctx, out_df, new_seed);
	memcpy(drbg_ctx->key, new_seed, keylen_byte);
	memcpy(drbg_ctx->V, new_seed + keylen_byte, blocklen_byte);

	drbg_ctx->reseed_counter = 1;
	free(seed_material);
}

void reseed_fnc_no_df(CTR_DRBG_CTX* drbg_ctx, unsigned char* entropy,
	unsigned int entropy_len, unsigned char* add_input, unsigned int add_len, LEA_KEY* key)
{
	unsigned char seed[seedlen] = { 0x00, };
	memcpy(seed, add_input, add_len);
	for (unsigned int i = 0; i < entropy_len; i++) {
		seed[i] ^= entropy[i];
	}
	unsigned char new_seed[seedlen] = { 0x00, };
	update(drbg_ctx, seed, new_seed);
	memcpy(drbg_ctx->key, new_seed, keylen_byte);
	memcpy(drbg_ctx->V, new_seed + keylen_byte, blocklen_byte);

	drbg_ctx->reseed_counter = 1;
}

void generate_fnc_use_df(CTR_DRBG_CTX* drbg_ctx, unsigned char* entropy, unsigned int entropy_len, unsigned char* add_input, unsigned int add_len
	,unsigned char* output, unsigned int outlen)
{
	unsigned char out_df[seedlen] = { 0x00, };
	unsigned char new_seed[seedlen] = { 0x00, };

	LEA_KEY key = { {0x00,},0x00, };
	lea_set_key(&key, lea256_CBC_key, 32);
	if (drbg_ctx->prediction_resistance_flag == 1) {
		reseed_fnc(drbg_ctx,entropy, entropy_len, add_input, add_len, &key);
		add_input = NULL;
		add_len = 0;
	}

	if (add_len != 0 && drbg_ctx->prediction_resistance_flag==0 ) {
		df(add_input, add_len, out_df, seedlen, &key);
		update(drbg_ctx, out_df, new_seed);
		memcpy(drbg_ctx->key, new_seed, keylen_byte);
		memcpy(drbg_ctx->V, new_seed + keylen_byte, blocklen_byte);
	}

	generator(drbg_ctx, output,outlen);
	update(drbg_ctx, out_df, new_seed); 
	memcpy(drbg_ctx->key, new_seed, keylen_byte);
	memcpy(drbg_ctx->V, new_seed + keylen_byte, blocklen_byte);
}

void generate_fnc_no_df(CTR_DRBG_CTX* drbg_ctx, unsigned char* entropy, unsigned int entropy_len, unsigned char* add_input, unsigned int add_len
	, unsigned char* output, unsigned int outlen)
{

	unsigned char seed[seedlen] = { 0x00, };
	unsigned char new_seed[seedlen] = { 0x00, };
	memcpy(seed, add_input, add_len);
	LEA_KEY key = { {0x00,},0x00, };
	lea_set_key(&key, lea256_CBC_key, 32);
	if (drbg_ctx->prediction_resistance_flag == 1) {
		reseed_fnc_no_df(drbg_ctx, entropy, entropy_len, add_input, add_len, &key);
		add_input = NULL;
		add_len = 0;
	}
	if (add_len != 0&&drbg_ctx->prediction_resistance_flag==0) {
		update(drbg_ctx, seed, new_seed);
		memcpy(drbg_ctx->key, new_seed, keylen_byte);
		memcpy(drbg_ctx->V, new_seed + keylen_byte, blocklen_byte);
	}
	generator(drbg_ctx, output, outlen);
	update(drbg_ctx, seed, new_seed); 
	memcpy(drbg_ctx->key, new_seed, keylen_byte);
	memcpy(drbg_ctx->V, new_seed + keylen_byte, blocklen_byte);
}

void make_ff(unsigned char* input, unsigned int len) {
	for (unsigned int i = 0; i < len; i++) {
		input[i] = 0xff;
	}
}

void make_ed(unsigned char* input, unsigned int len) {
	for (unsigned int i = 0; i < len; i++) {
		input[i] = 0xed;
	}
}

void ctr_drbg_ctx_free_use_p(CTR_DRBG_CTX* drbg_ctx)
{
	memset(drbg_ctx->V, 0, blocklen_byte);
	memset(drbg_ctx->key, 0, keylen_byte);
	drbg_ctx->reseed_counter = 0;
	drbg_ctx->prediction_resistance_flag = 1;
}

void ctr_drbg_ctx_free_no_p(CTR_DRBG_CTX* drbg_ctx)
{
	memset(drbg_ctx->V, 0, blocklen_byte);
	memset(drbg_ctx->key, 0, keylen_byte);
	drbg_ctx->reseed_counter = 0;
	drbg_ctx->prediction_resistance_flag = 0;
}

#if defined(speed_test)
__int64 cpucycle(void) { return __rdtsc(); }

int main() {

	unsigned long long cycles, cycles1, cycles2, cycle = 0;
	CTR_DRBG_CTX drbg_ctx = { {0x00,},0x00, };
	unsigned char entropy[96] = "4E8C3F143B8078687B4DA65F5AA20D36F3C03D4DF42BF47EA1A540AD1C5CE4A0E363FD119A5FE5020B8358516BBED58C";
	unsigned char entropy_input[48] = { 0x00, };
	unsigned int entropy_len = 48;
	unsigned char entropy_reseed[96] = "DCA4AE9C1F5C43E76465E60437A72F3C95BCA118AFA489BCEBBA29762CE616975315DF8206E6EF02B0A6B5E1C87F02B6";
	unsigned char entropy_reseed_input[48] = { 0x00, };
	unsigned char nonce[32] = "81F3DC509A3A96BFBBCF265A436AFB29";
	unsigned int Noncelen = 16;
	unsigned char Nonce[16] = { 0x00, };
	unsigned char personalstring[96] = "79B8B4C3FCD1C7B4EFEFCBD066621F0668AD8E0AAC382FA6A0458951AF25FB02C4AC5C460AE2DE91F7FB38D1888A0449";
	unsigned int per_len = 0;
	unsigned char personal_input[48] = { 0x00, };
	unsigned char add[96] = "CE5FD137421F7CBD5D0083EB4B0D154258F47DF8B1B7004A6FA50413D189789CC9216FB6BBD10E068199A9A1B24529D9";
	unsigned int add_len = 0;
	unsigned char add_input[48] = { 0x00, };
	unsigned char returnedbits[128] = { 0x00, };
	unsigned int returned_len = 128;
	for (int i = 0; i < 48; i++) {
		entropy_input[i] = entropy[i] + entropy[i + 1];
	}
	for (int i = 0; i < 48; i++) {
		entropy_reseed_input[i] = entropy_reseed[i] + entropy_reseed[i + 1];
	}
	for (int i = 0; i < 48; i++) {
		add_input[i] = add[i] + add[i + 1];
	}
	for (int i = 0; i < 48; i++) {
		personal_input[i] = personalstring[i] + personalstring[i + 1];
	}
	for (int i = 0; i < 16; i++) {
		Nonce[i] = nonce[i] + nonce[i + 1];
	}
	LEA_KEY key = { {0x00,}, };
	lea_set_key(&key, lea256_CBC_key, 32);
	cycles1 = cpucycle();
	drbg_ctx.prediction_resistance_flag = 1;
	for (int i = 0; i < 10000; i++) {
		Instante_fnc_no_df(&drbg_ctx,entropy, entropy_len,Nonce,Noncelen,personal_input,per_len);
		generate_fnc_no_df(&drbg_ctx, entropy_reseed, entropy_len, add_input, add_len, returnedbits, returned_len);
		generate_fnc_no_df(&drbg_ctx, entropy_reseed, entropy_len, add_input, add_len, returnedbits, returned_len);
	}

	cycles2 = cpucycle();
	cycles = cycles2 - cycles1;
	printf("cycles : %10lld", cycles / 10000);
	printf("\n");
	for (int i = 0; i < returned_len; i++)
		printf("%02X", returnedbits[i]);
	return 0;
}

#elif defined(no_df_use_pr)
int main() // ctr_drbg no df use pr
{
	file* req, * rsp;
	req = fopen("ctr_drbg(lea-256(no df)(use pr))_kat.req", "rb");
	rsp = fopen("ctr_drbg(lea-256(no df)(use pr))_kat.rsp", "w");
	if (rsp == null) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == null) {
		printf("req open 실패!!\n");
		return 1;
	}
	ctr_drbg_ctx drbg_ctx = { {0x00,},0x00, };
	unsigned char tmp[100] = { 0x00, };
	unsigned int rr = 0;
	unsigned int rx = 0;
	unsigned int a = 0;
	for (unsigned int x = 0; x < 4; x++) {
		//=========================================================기본 정보
		a = fscanf(req, "%s", tmp);
		printf("%s", tmp);
		fprintf(rsp, "\n%s", tmp);
		a = fscanf(req, "%s", tmp);
		printf(" %s", tmp);
		fprintf(rsp, " %s", tmp);
		a = fscanf(req, "%s", tmp);
		printf(" %s", tmp);
		fprintf(rsp, " %s", tmp);

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%s", tmp);
		printf("%s", tmp);
		fprintf(rsp, "%s", tmp);
		drbg_ctx.prediction_resistance_flag = 1;

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%d]", &rr);
		unsigned int entropy_input_len = rr;
		unsigned int entropy_input_len_byte = entropy_input_len >> 3;
		printf("%d]", entropy_input_len);
		fprintf(rsp, "%d]", rr);

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%d]", &rr);
		unsigned int nonce_len = rr;
		unsigned int nonce_len_byte = rr >> 3;
		printf("%d]", nonce_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int personal_string_len = rr;
		unsigned int personal_string_len_byte = rr >> 3;
		printf("%d]", personal_string_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int add_input_len = rr;
		unsigned int add_input_len_byte = rr >> 3;
		printf("%d]", add_input_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int outlen = rr;
		unsigned int outlen_byte = rr >> 3;
		printf("%d]", outlen);
		fprintf(rsp, "%d]", rr);
		//==============================================시작 정보를 이용한 기본 선언
		unsigned char* entropyinput = null;
		entropyinput = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* nonce = null;
		nonce = (unsigned char*)calloc(nonce_len_byte, sizeof(unsigned char));
		unsigned char* personal_string = null;
		personal_string = (unsigned char*)calloc(personal_string_len_byte, sizeof(unsigned char));
		unsigned char* additional_input1 = null;
		additional_input1 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input2 = null;
		additional_input2 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* entropypr1 = null;
		entropypr1 = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* entropypr2 = null;
		entropypr2 = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* output = null;
		output = (unsigned char*)calloc(outlen_byte, sizeof(unsigned char));
		//====================================================처음 부분 시작
		for (unsigned int i = 0; i < 15; i++) {
			fscanf(req, "%s = ", tmp);
			printf("\n\n%s = ", tmp);
			fprintf(rsp, "\n\n%s = ", tmp);
			fscanf(req, "%d", &rr);
			printf("%d", rr);
			fprintf(rsp, "%d", rr);
			rr = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				entropyinput[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < nonce_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				nonce[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < personal_string_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				personal_string[w] = rx;
				printf("%02x", personal_string[w]);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				entropypr1[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < add_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				additional_input1[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				entropypr2[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (add_input_len_byte != 0) {
				for (unsigned int w = 0; w < add_input_len_byte; w++) {
					fscanf(req, "%02x", &rx);
					additional_input2[w] = rx;
					printf("%02x", rx);
					fprintf(rsp, "%02x", rx);
				}
			}
			rx = 0;
			fprintf(rsp, "\nreturnedbitslen = ");
			printf("\nreturnedbitslen = ");
			instante_fnc_no_df(&drbg_ctx,entropyinput,entropy_input_len_byte,nonce,nonce_len_byte,personal_string,personal_string_len_byte,output,outlen_byte);
			generate_fnc_no_df(&drbg_ctx, entropypr1, entropy_input_len_byte, additional_input1, add_input_len_byte, output, outlen_byte);
			generate_fnc_no_df(&drbg_ctx, entropypr2, entropy_input_len_byte, additional_input2, add_input_len_byte, output, outlen_byte);
			for (unsigned int w = 0; w < outlen_byte; w++) {
				printf("%02x", output[w]);
				fprintf(rsp, "%02x", output[w]);
			}
			rx = 0;
			ctr_drbg_ctx_free_use_p(&drbg_ctx);

		}
		free(entropyinput);
		free(nonce);
		free(personal_string);
		free(additional_input1);
		free(additional_input2);
		free(entropypr1);
		free(entropypr2);
		free(output);
		fprintf(rsp, "\n");
	}
	fclose(rsp);
	fclose(req);
	return 0;
}


#elif defined(use_df_use_pr)
int main() // ctr_drbg use df use pr
{
	file* req, * rsp;
	req = fopen("ctr_drbg(lea-256(use df)(use pr))_kat.req", "rb");
	rsp = fopen("ctr_drbg(lea-256(use df)(use pr))_kat.rsp", "w");
	if (rsp == null) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == null) {
		printf("req open 실패!!\n");
		return 1;
	}
	ctr_drbg_ctx drbg_ctx = { {0x00,},0x00, };
	unsigned char tmp[100] = { 0x00, };
	unsigned int rr = 0;
	unsigned int rx = 0;
	unsigned int a = 0;
	for (unsigned int x = 0; x < 4; x++) {
		=========================================================기본 정보
		a = fscanf(req, "%s", tmp);
		printf("%s", tmp);
		fprintf(rsp, "\n%s", tmp);
		a = fscanf(req, "%s", tmp);
		printf(" %s", tmp);
		fprintf(rsp, " %s", tmp);
		a = fscanf(req, "%s", tmp);
		printf(" %s", tmp);
		fprintf(rsp, " %s", tmp);

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%s", tmp);
		printf("%s", tmp);
		fprintf(rsp, "%s", tmp);
		drbg_ctx.prediction_resistance_flag = 1;

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%d]", &rr);
		unsigned int entropy_input_len = rr;
		unsigned int entropy_input_len_byte = entropy_input_len >> 3;
		printf("%d]", entropy_input_len);
		fprintf(rsp, "%d]", rr);

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%d]", &rr);
		unsigned int nonce_len = rr;
		unsigned int nonce_len_byte = rr >> 3;
		printf("%d]", nonce_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int personal_string_len = rr;
		unsigned int personal_string_len_byte = rr >> 3;
		printf("%d]", personal_string_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int add_input_len = rr;
		unsigned int add_input_len_byte = rr >> 3;
		printf("%d]", add_input_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int outlen = rr;
		unsigned int outlen_byte = rr >> 3;
		printf("%d]", outlen);
		fprintf(rsp, "%d]", rr);
		==============================================시작 정보를 이용한 기본 선언
		unsigned char* entropyinput = null;
		entropyinput = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* nonce = null;
		nonce = (unsigned char*)calloc(nonce_len_byte, sizeof(unsigned char));
		unsigned char* personal_string = null;
		personal_string = (unsigned char*)calloc(personal_string_len_byte, sizeof(unsigned char));
		unsigned char* additional_input1 = null;
		additional_input1 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input2 = null;
		additional_input2 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* entropypr1 = null;
		entropypr1 = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* entropypr2 = null;
		entropypr2 = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* output = null;
		output = (unsigned char*)calloc(outlen_byte, sizeof(unsigned char));
		====================================================처음 부분 시작
		for (unsigned int i = 0; i < 15; i++) {
			fscanf(req, "%s = ", tmp);
			printf("\n\n%s = ", tmp);
			fprintf(rsp, "\n\n%s = ", tmp);
			fscanf(req, "%d", &rr);
			printf("%d", rr);
			fprintf(rsp, "%d", rr);
			rr = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				entropyinput[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < nonce_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				nonce[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < personal_string_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				personal_string[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				entropypr1[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < add_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				additional_input1[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				entropypr2[w] = rx;
				printf("%02x", rx);
				fprintf(rsp, "%02x", rx);
			}
			rx = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (add_input_len_byte != 0) {
				for (unsigned int w = 0; w < add_input_len_byte; w++) {
					fscanf(req, "%02x", &rx);
					additional_input2[w] = rx;
					printf("%02x", rx);
					fprintf(rsp, "%02x", rx);
				}
			}
			rx = 0;
			fprintf(rsp, "\nreturnedbitslen = ");
			printf("\nreturnedbitslen = ");
			instante_fnc_use_df(&drbg_ctx,entropyinput,entropy_input_len_byte,nonce,nonce_len_byte,personal_string,personal_string_len_byte,output,outlen_byte);
			generate_fnc_use_df(&drbg_ctx, entropypr1, entropy_input_len_byte, additional_input1, add_input_len_byte, output, outlen_byte);
			generate_fnc_use_df(&drbg_ctx, entropypr2, entropy_input_len_byte, additional_input2, add_input_len_byte, output, outlen_byte);
			for (unsigned int w = 0; w < outlen_byte; w++) {
				printf("%02x", output[w]);
				fprintf(rsp, "%02x", output[w]);
			}
			rx = 0;
			ctr_drbg_ctx_free_use_p(&drbg_ctx);

		}
		free(entropyinput);
		free(nonce);
		free(personal_string);
		free(additional_input1);
		free(additional_input2);
		free(entropypr1);
		free(entropypr2);
		free(output);
		fprintf(rsp, "\n");
	}
	fclose(rsp);
	fclose(req);
	return 0;
}



#elif defined(use_df_no_pr)
int main() // ctr_drbg use df no pr
{
	file* req, * rsp;
	req = fopen("ctr_drbg(lea-256(use df)(no pr))_kat.req", "rb");
	rsp = fopen("ctr_drbg(lea-256(use df)(no pr))_kat.rsp", "w");
	if (rsp == null) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == null) {
		printf("req open 실패!!\n");
		return 1;
	}
	ctr_drbg_ctx drbg_ctx = { {0x00,},0x00, };
	unsigned char tmp[100] = { 0x00, };
	unsigned int rr = 0;
	unsigned int rx = 0;
	unsigned int a = 0;
	for (unsigned int x = 0; x < 4; x++) {
		//=========================================================기본 정보
		a = fscanf(req, "%s", tmp);
		printf("%s", tmp);
		fprintf(rsp, "%s", tmp);
		a = fscanf(req, "%s", tmp);
		printf(" %s", tmp);
		fprintf(rsp, " %s", tmp);
		a = fscanf(req, "%s", tmp);
		printf(" %s", tmp);
		fprintf(rsp, " %s", tmp);

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%s", tmp);
		printf("%s", tmp);
		fprintf(rsp, "%s", tmp);
		drbg_ctx.prediction_resistance_flag = 0;

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%d]", &rr);
		unsigned int entropy_input_len = rr;
		unsigned int entropy_input_len_byte = entropy_input_len >> 3;
		printf("%d]", entropy_input_len);
		fprintf(rsp, "%d]", rr);

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%d]", &rr);
		unsigned int nonce_len = rr;
		unsigned int nonce_len_byte = rr >> 3;
		printf("%d]", nonce_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int personal_string_len = rr;
		unsigned int personal_string_len_byte = rr >> 3;
		printf("%d]", personal_string_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int add_input_len = rr;
		unsigned int add_input_len_byte = rr >> 3;
		printf("%d]", add_input_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int outlen = rr;
		unsigned int outlen_byte = rr >> 3;
		printf("%d]", outlen);
		fprintf(rsp, "%d]", rr);
		//==============================================시작 정보를 이용한 기본 선언
		unsigned char* entropyinput = null;
		entropyinput = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* nonce = null;
		nonce = (unsigned char*)calloc(nonce_len_byte, sizeof(unsigned char));
		unsigned char* personal_string = null;
		personal_string = (unsigned char*)calloc(personal_string_len_byte, sizeof(unsigned char));
		unsigned char* entropyreseedinput = null;
		entropyreseedinput = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input_reseed = null;
		additional_input_reseed = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input1 = null;
		additional_input1 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input2 = null;
		additional_input2 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));

		unsigned char* output = null;
		output = (unsigned char*)calloc(outlen_byte, sizeof(unsigned char));
		//====================================================처음 부분 시작
		for (unsigned int i = 0; i < 15; i++) {
			rr = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n\n%s = ", tmp);
			fprintf(rsp, "\n\n%s = ", tmp);
			fscanf(req, "%d", &rr);
			printf("%d", rr);
			fprintf(rsp, "%d", rr);
			rr = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				entropyinput[w] = rx;
				printf("%02x", entropyinput[w]);
				fprintf(rsp, "%02x", rx);
			}

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < nonce_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				nonce[w] = rx;
				printf("%02x", nonce[w]);
				fprintf(rsp, "%02x", rx);
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (personal_string_len_byte != 0) {
				for (unsigned int w = 0; w < personal_string_len_byte; w++) {
					fscanf(req, "%02x", &rx);
					personal_string[w] = rx;
					printf("%02x", personal_string[w]);
					fprintf(rsp, "%02x", rx);
				}
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				entropyreseedinput[w] = rx;
				printf("%02x", entropyreseedinput[w]);
				fprintf(rsp, "%02x", rx);
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);

			for (unsigned int w = 0; w < add_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				additional_input_reseed[w] = rx;
				printf("%02x", additional_input_reseed[w]);
				fprintf(rsp, "%02x", rx);
			}

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (add_input_len_byte != 0) {
				for (unsigned int w = 0; w < add_input_len_byte; w++) {
					fscanf(req, "%02x", &rx);
					additional_input1[w] = rx;
					printf("%02x", additional_input1[w]);
					fprintf(rsp, "%02x", rx);
				}
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (add_input_len_byte != 0) {
				for (unsigned int w = 0; w < add_input_len_byte; w++) {
					fscanf(req, "%02x", &rx);
					additional_input2[w] = rx;
					printf("%02x", additional_input2[w]);
					fprintf(rsp, "%02x", rx);
				}
			}

			lea_key key = { {0x00,},0x00, };
			lea_set_key(&key, lea256_cbc_key, 32);
			fprintf(rsp, "\nreturnedbits = ");
			printf("\nreturnedbits = ");
			instante_fnc_use_df(&drbg_ctx, entropyinput, entropy_input_len_byte, nonce, nonce_len_byte, personal_string, personal_string_len_byte);
			reseed_fnc(&drbg_ctx, entropyreseedinput, entropy_input_len_byte, additional_input_reseed, add_input_len_byte, &key);
			generate_fnc_use_df(&drbg_ctx, entropyreseedinput, entropy_input_len_byte, additional_input1, add_input_len_byte, output, outlen_byte);
			
			generate_fnc_use_df(&drbg_ctx, entropyreseedinput, entropy_input_len_byte, additional_input2, add_input_len_byte, output, outlen_byte);
			for (unsigned int w = 0; w < outlen_byte; w++) {
				printf("%02x", output[w]);
				fprintf(rsp, "%02x", output[w]);
			}
			printf("\n");
			ctr_drbg_ctx_free_no_p(&drbg_ctx);
		}
		free(entropyinput);
		free(nonce);
		free(personal_string);
		free(entropyreseedinput);
		free(additional_input_reseed);
		free(additional_input1);
		free(additional_input2);
		free(output);
		fprintf(rsp, "\n");
	}
	fclose(rsp);
	fclose(req);
	return 0;
}



#elif defined(no_df_no_pr)
int main() // ctr_drbg no df no pr
{
	file* req, * rsp;
	req = fopen("ctr_drbg(lea-256(no df)(no pr))_kat.req", "rb");
	rsp = fopen("ctr_drbg(lea-256(no df)(no pr))_kat.rsp", "w");
	if (rsp == null) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == null) {
		printf("req open 실패!!\n");
		return 1;
	}
	ctr_drbg_ctx drbg_ctx = { {0x00,},0x00, };
	unsigned char tmp[100] = { 0x00, };
	unsigned int rr = 0;
	unsigned int rx = 0;
	unsigned int a = 0;
	for (unsigned int x = 0; x < 4; x++) {
		//=========================================================기본 정보
		a = fscanf(req, "%s", tmp);
		printf("%s", tmp);
		fprintf(rsp, "%s", tmp);
		a = fscanf(req, "%s", tmp);
		printf(" %s", tmp);
		fprintf(rsp, " %s", tmp);
		a = fscanf(req, "%s", tmp);
		printf(" %s", tmp);
		fprintf(rsp, " %s", tmp);

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%s", tmp);
		printf("%s", tmp);
		fprintf(rsp, "%s", tmp);
		drbg_ctx.prediction_resistance_flag = 0;

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%d]", &rr);
		unsigned int entropy_input_len = rr;
		unsigned int entropy_input_len_byte = entropy_input_len >> 3;
		printf("%d]", entropy_input_len);
		fprintf(rsp, "%d]", rr);

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%d]", &rr);
		unsigned int nonce_len = rr;
		unsigned int nonce_len_byte = rr >> 3;
		printf("%d]", nonce_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int personal_string_len = rr;
		unsigned int personal_string_len_byte = rr >> 3;
		printf("%d]", personal_string_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int add_input_len = rr;
		unsigned int add_input_len_byte = rr >> 3;
		printf("%d]", add_input_len);
		fprintf(rsp, "%d]", rr);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &rr);
		unsigned int outlen = rr;
		unsigned int outlen_byte = rr >> 3;
		printf("%d]", outlen);
		fprintf(rsp, "%d]", rr);
		//==============================================시작 정보를 이용한 기본 선언
		unsigned char* entropyinput = null;
		entropyinput = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* nonce = null;
		nonce = (unsigned char*)calloc(nonce_len_byte, sizeof(unsigned char));
		unsigned char* personal_string = null;
		personal_string = (unsigned char*)calloc(personal_string_len_byte, sizeof(unsigned char));
		unsigned char* entropyreseedinput = null;
		entropyreseedinput = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input_reseed = null;
		additional_input_reseed = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input1 = null;
		additional_input1 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input2 = null;
		additional_input2 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));

		unsigned char* output = null;
		output = (unsigned char*)calloc(outlen_byte, sizeof(unsigned char));
		//====================================================처음 부분 시작
		for (unsigned int i = 0; i < 15; i++) {
			rr = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n\n%s = ", tmp);
			fprintf(rsp, "\n\n%s = ", tmp);
			fscanf(req, "%d", &rr);
			printf("%d", rr);
			fprintf(rsp, "%d", rr);
			rr = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				entropyinput[w] = rx;
				printf("%02x", entropyinput[w]);
				fprintf(rsp, "%02x", rx);
			}

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < nonce_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				nonce[w] = rx;
				printf("%02x", nonce[w]);
				fprintf(rsp, "%02x", rx);
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (personal_string_len_byte != 0) {
				for (unsigned int w = 0; w < personal_string_len_byte; w++) {
					fscanf(req, "%02x", &rx);
					personal_string[w] = rx;
					printf("%02x", personal_string[w]);
					fprintf(rsp, "%02x", rx);
				}
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				entropyreseedinput[w] = rx;
				printf("%02x", entropyreseedinput[w]);
				fprintf(rsp, "%02x", rx);
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);

			for (unsigned int w = 0; w < add_input_len_byte; w++) {
				fscanf(req, "%02x", &rx);
				additional_input_reseed[w] = rx;
				printf("%02x", additional_input_reseed[w]);
				fprintf(rsp, "%02x", rx);
			}

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (add_input_len_byte != 0) {
				for (unsigned int w = 0; w < add_input_len_byte; w++) {
					fscanf(req, "%02x", &rx);
					additional_input1[w] = rx;
					printf("%02x", additional_input1[w]);
					fprintf(rsp, "%02x", rx);
				}
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (add_input_len_byte != 0) {
				for (unsigned int w = 0; w < add_input_len_byte; w++) {
					fscanf(req, "%02x", &rx);
					additional_input2[w] = rx;
					printf("%02x", additional_input2[w]);
					fprintf(rsp, "%02x", rx);
				}
			}

			lea_key key = { {0x00,},0x00, };
			lea_set_key(&key, lea256_cbc_key, 32);
			fprintf(rsp, "\nreturnedbits = ");
			printf("\nreturnedbits = ");
			instante_fnc_no_df(&drbg_ctx, entropyinput, entropy_input_len_byte, nonce, nonce_len_byte, personal_string, personal_string_len_byte);
			reseed_fnc_no_df(&drbg_ctx, entropyreseedinput, entropy_input_len_byte, additional_input_reseed, add_input_len_byte, &key);
			generate_fnc_no_df(&drbg_ctx, entropyreseedinput, entropy_input_len_byte, additional_input1, add_input_len_byte, output, outlen_byte);
		
			generate_fnc_no_df(&drbg_ctx, entropyreseedinput, entropy_input_len_byte, additional_input2, add_input_len_byte, output, outlen_byte);
			for (unsigned int w = 0; w < outlen_byte; w++) {
				printf("%02x", output[w]);
				fprintf(rsp, "%02x", output[w]);
			}
			printf("\n");
			ctr_drbg_ctx_free_no_p(&drbg_ctx);
		}
		free(entropyinput);
		free(nonce);
		free(personal_string);
		free(entropyreseedinput);
		free(additional_input_reseed);
		free(additional_input1);
		free(additional_input2);
		free(output);
		fprintf(rsp, "\n");
	}
	fclose(rsp);
	fclose(req);
	return 0;
}




