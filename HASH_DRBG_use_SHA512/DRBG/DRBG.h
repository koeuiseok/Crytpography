
#ifndef DRBG_H
#define DRBG_H

#include "SHA512.h"

#define SEED_LEN 888
#define SEED_LEN_BYTE 111

#define HASH_OUTPUT_LEN 512
#define HASH_OUTPUT_LEN_BYTE 64

#define N 0x00000378
#define len_seed 2

typedef struct hash_drbg_ctx {
	unsigned char V[SEED_LEN_BYTE];
	unsigned char C[SEED_LEN_BYTE];
	unsigned char reseed_counter;

	unsigned int prediction_resistance_flag;
}Hash_DRBG_CTX;

void hash_drbg_ctx_free_use_p(Hash_DRBG_CTX* drbg_ctx);
void hash_drbg_ctx_free_no_p(Hash_DRBG_CTX* drbg_ctx);

void hash_df(unsigned char* input, unsigned char* output, unsigned int input_len);

void Instant_Fnc(Hash_DRBG_CTX* drbg_ctx, unsigned char* entropy_input,
	unsigned int input_len, unsigned char* nonce, unsigned int nonce_len,
	unsigned char* personalization_string, unsigned int per_string_len);

void reseed_fnc(Hash_DRBG_CTX* drbg_ctx, unsigned char* entropy_input,
	unsigned int input_len, unsigned char* add_input, unsigned int add_input_len);

void generate_fnc(Hash_DRBG_CTX* drbg_ctx, unsigned char* reseed_entropy, unsigned int entropy_len,
	unsigned char* add_input, unsigned int input_len, unsigned char* output, unsigned int outlen);

void add_sub(Hash_DRBG_CTX* drbg_ctx, unsigned char* w);

void add2(Hash_DRBG_CTX* drbg_ctx, unsigned char* H);

void add_same(Hash_DRBG_CTX* drbg_ctx);

#endif
