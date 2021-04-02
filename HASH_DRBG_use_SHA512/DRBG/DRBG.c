#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SHA512.h"
#include "DRBG.h"

void hash_df(unsigned char* input, unsigned char* output, unsigned int input_len ) 
{
	unsigned char counter = 1;
	unsigned char temp1 [HASH_OUTPUT_LEN_BYTE] = { 0, };
	unsigned char temp2[HASH_OUTPUT_LEN_BYTE] = { 0, };
	unsigned int new_len = 0;
	new_len = input_len + 5;
	unsigned char* new_input = NULL;
	new_input = (unsigned char*)calloc(new_len, sizeof(unsigned char));
	new_input[0] = 0x01;
	new_input[1] = 0x00;
	new_input[2] = 0x00;
	new_input[3] = 0x03;
	new_input[4] = 0x78;
	memcpy(new_input + 5, input, input_len);

	SHA512_Encrpyt(new_input, new_len, temp1);
	new_input[0] = 0x02;
	SHA512_Encrpyt(new_input, new_len, temp2);

	memcpy(output, temp1, HASH_OUTPUT_LEN_BYTE);
	memcpy(output+HASH_OUTPUT_LEN_BYTE, temp2, HASH_OUTPUT_LEN_BYTE-17);
	free(new_input);
}

void Instant_Fnc (Hash_DRBG_CTX* drbg_ctx,unsigned char* entropy_input, 
	unsigned int input_len ,unsigned char* nonce, unsigned int nonce_len,
	unsigned char* personalization_string, unsigned int per_string_len)
{
	
	unsigned int seed_material_len = 0;
	seed_material_len = input_len + nonce_len + per_string_len;
	unsigned char* seed_material = NULL;
	seed_material = (unsigned char*)calloc(seed_material_len, sizeof(unsigned char));
	memcpy(seed_material, entropy_input, input_len);
	memcpy(seed_material+input_len, nonce, nonce_len);
	if (per_string_len !=0) {
		memcpy(seed_material + input_len + nonce_len, personalization_string, per_string_len);
	}
	unsigned char seed[111] = { 0, };

	hash_df(seed_material, seed, seed_material_len);
	unsigned char V2[SEED_LEN_BYTE + 1] = { 0x00,0x00, };
	memcpy(drbg_ctx->V, seed, SEED_LEN_BYTE);
	memcpy(V2+1, drbg_ctx->V, SEED_LEN_BYTE);
	hash_df(V2, drbg_ctx->C, SEED_LEN_BYTE+1);
	drbg_ctx->reseed_counter = 1;

	free(seed_material);
	
}

void reseed_fnc(Hash_DRBG_CTX* drbg_ctx, unsigned char* entropy_input,
	unsigned int input_len, unsigned char* add_input, unsigned int add_input_len)
{
	unsigned int seed_material_len = 0;
	seed_material_len = input_len + add_input_len + SEED_LEN_BYTE + 1;
	unsigned char* seed_material = NULL;
	seed_material = (unsigned char*)calloc(seed_material_len, sizeof(unsigned char));
	seed_material[0] = 0x01;

	memcpy(seed_material + 1, drbg_ctx->V, SEED_LEN_BYTE);
	memcpy(seed_material + 1 + SEED_LEN_BYTE, entropy_input, input_len);

	if (add_input_len !=0) {
		memcpy(seed_material + 1 + SEED_LEN_BYTE + input_len, add_input, add_input_len);
	}

	unsigned char seed[SEED_LEN_BYTE] = { 0x00, };
	hash_df(seed_material, seed, seed_material_len);
	unsigned char V2[SEED_LEN_BYTE + 1] = { 0x00, };
	memcpy(drbg_ctx->V, seed, SEED_LEN_BYTE);
	memcpy(V2 + 1,drbg_ctx->V, SEED_LEN_BYTE);
	hash_df(V2,drbg_ctx->C,SEED_LEN_BYTE+1);
	drbg_ctx->reseed_counter = 1;

	free(seed_material);
}

void hash_drbg_ctx_free_use_p(Hash_DRBG_CTX* drbg_ctx)
{
	memset(drbg_ctx->V, 0, SEED_LEN_BYTE);
	memset(drbg_ctx->C, 0, SEED_LEN_BYTE);
	drbg_ctx->reseed_counter = 0;
	drbg_ctx->prediction_resistance_flag = 1;
}

void hash_drbg_ctx_free_no_p(Hash_DRBG_CTX* drbg_ctx)
{
	memset(drbg_ctx->V, 0, SEED_LEN_BYTE);
	memset(drbg_ctx->C, 0, SEED_LEN_BYTE);
	drbg_ctx->reseed_counter = 0;
	drbg_ctx->prediction_resistance_flag = 0;
}

void generate_fnc(Hash_DRBG_CTX* drbg_ctx,unsigned char* reseed_entropy, unsigned int entropy_len, 
	unsigned char* add_input, unsigned int input_len,unsigned char* output, unsigned int outlen)
{
	unsigned char w[HASH_OUTPUT_LEN_BYTE] = { 0, };
	unsigned char carry0 = 0, carry = 0;
	
	if (drbg_ctx->prediction_resistance_flag == 1)
	{
		reseed_fnc(drbg_ctx, reseed_entropy, entropy_len, add_input, input_len);
		add_input = NULL;
		input_len = 0;
	}
	
	if ((input_len !=0 )) {
		unsigned char* new_V = NULL;
		unsigned int new_len = SEED_LEN_BYTE + input_len + 1;
		new_V = (unsigned char*)calloc(SEED_LEN_BYTE + input_len + 1, sizeof(unsigned char));
		new_V[0] = 0x02;
		memcpy(new_V+1,drbg_ctx->V, SEED_LEN_BYTE);
		memcpy(new_V + SEED_LEN_BYTE + 1, add_input, input_len);
		SHA512_Encrpyt(new_V,new_len, w);
		for (int i = HASH_OUTPUT_LEN_BYTE-1; i >= 0; i--) {
			carry = carry0;
			carry0 = (drbg_ctx->V[47 + i] + w[i]+carry)>>8;
			drbg_ctx->V[47 + i] += w[i]+carry;
		}
		for (int i = 46; i > 0; i--) {
			carry = carry0;
			carry0 = (drbg_ctx->V[i]+carry)>>8;
			drbg_ctx->V[i] += carry;
		}
		drbg_ctx->V[0] += carry0;
		free(new_V);
	}

	unsigned char out_buffer[HASH_OUTPUT_LEN_BYTE] = { 0, };
	unsigned int cnt = 0;
	unsigned char V_buffer[SEED_LEN_BYTE+1] = { 0x03,0x00, };
	memcpy(V_buffer+1,drbg_ctx->V,SEED_LEN_BYTE);
	int round = outlen / HASH_OUTPUT_LEN_BYTE;
	for(int h=0; h<round; h++) {
		SHA512_Encrpyt(drbg_ctx->V, SEED_LEN_BYTE, out_buffer);
		carry = 1;
		carry0 = 1;
		memcpy(output + (cnt * HASH_OUTPUT_LEN_BYTE), out_buffer, HASH_OUTPUT_LEN_BYTE);
		for (int i = SEED_LEN_BYTE-1; i > 0; i--) {
			carry = carry0;
			carry0 = (drbg_ctx->V[i] + carry) >> 8;
			drbg_ctx->V[i] += carry;
		}
		drbg_ctx->V[0] += carry0;
		memcpy(output+HASH_OUTPUT_LEN_BYTE*cnt, out_buffer, HASH_OUTPUT_LEN_BYTE);
		cnt++;
	}

	SHA512_Encrpyt(V_buffer,SEED_LEN_BYTE+1,out_buffer);
	memcpy(drbg_ctx->V, V_buffer + 1, SEED_LEN_BYTE);
	carry0 = (drbg_ctx->V[SEED_LEN_BYTE - 1] + drbg_ctx->reseed_counter 
		+ out_buffer[HASH_OUTPUT_LEN_BYTE - 1]+drbg_ctx->C[SEED_LEN_BYTE-1])>>8;
	drbg_ctx->V[SEED_LEN_BYTE - 1] += drbg_ctx->C[SEED_LEN_BYTE - 1]+ drbg_ctx->reseed_counter 
		+ out_buffer[HASH_OUTPUT_LEN_BYTE - 1];
	for (int i = HASH_OUTPUT_LEN_BYTE - 2; i >= 0; i--) {
		carry = carry0;
		carry0 = (drbg_ctx->V[47 + i]+ drbg_ctx->C[47 + i] + out_buffer[i] + carry) >> 8;
		drbg_ctx->V[47 + i] += drbg_ctx->C[47 + i]+out_buffer[i] + carry;
	}
	for (int i = 46; i > 0; i--) {
		carry = carry0;
		carry0 = (drbg_ctx->V[i] + drbg_ctx->C[i] + carry) >> 8;
		drbg_ctx->V[i] += drbg_ctx->C[i] + carry;
	}
	drbg_ctx->V[0] += drbg_ctx->C[0]+carry0;
	drbg_ctx->reseed_counter += 1;

}

void generate2_fnc(Hash_DRBG_CTX* drbg_ctx, unsigned char* reseed_entropy, unsigned int entropy_len,
	unsigned char* add_input, unsigned int input_len, unsigned char* output, unsigned int outlen)
{
	unsigned char w[HASH_OUTPUT_LEN_BYTE] = { 0, };
	unsigned char carry0 = 0, carry = 0;

	if (drbg_ctx->prediction_resistance_flag == 1)
	{
		reseed_fnc(drbg_ctx, reseed_entropy, entropy_len, add_input, input_len);
		add_input = NULL;
		input_len = 0;
	}

	if ((input_len != 0)) {
		unsigned char* new_V = NULL;
		unsigned int new_len = SEED_LEN_BYTE + input_len + 1;
		new_V = (unsigned char*)calloc(SEED_LEN_BYTE + input_len + 1, sizeof(unsigned char));
		new_V[0] = 0x02;
		memcpy(new_V + 1, drbg_ctx->V, SEED_LEN_BYTE);
		memcpy(new_V + SEED_LEN_BYTE + 1, add_input, input_len);
		SHA512_Encrpyt(new_V, new_len, w);
		for (int i = HASH_OUTPUT_LEN_BYTE - 1; i >= 0; i--) {
			carry = carry0;
			carry0 = (drbg_ctx->V[47 + i] + w[i] + carry) >> 8;
			drbg_ctx->V[47 + i] += w[i] + carry;
		}
		for (int i = 46; i > 0; i--) {
			carry = carry0;
			carry0 = (drbg_ctx->V[i] + carry) >> 8;
			drbg_ctx->V[i] += carry;
		}
		drbg_ctx->V[0] += carry0;
		free(new_V);
	}

	unsigned char out_buffer[HASH_OUTPUT_LEN_BYTE] = { 0, };
	unsigned int cnt = 0;
	unsigned char V_buffer[SEED_LEN_BYTE + 1] = { 0x03,0x00, };
	memcpy(V_buffer + 1, drbg_ctx->V, SEED_LEN_BYTE);
	int round = outlen / HASH_OUTPUT_LEN_BYTE;
	for (int h = 0; h < round; h++) {
		SHA512_Encrpyt(drbg_ctx->V, SEED_LEN_BYTE, out_buffer);
		carry = 1;
		carry0 = 1;
		memcpy(output + (cnt * HASH_OUTPUT_LEN_BYTE), out_buffer, HASH_OUTPUT_LEN_BYTE);
		for (int i = SEED_LEN_BYTE - 1; i > 0; i--) {
			carry = carry0;
			carry0 = (drbg_ctx->V[i] + carry) >> 8;
			drbg_ctx->V[i] += carry;
		}
		drbg_ctx->V[0] += carry0;
		memcpy(output + HASH_OUTPUT_LEN_BYTE * cnt, out_buffer, HASH_OUTPUT_LEN_BYTE);
		cnt++;
	}
}