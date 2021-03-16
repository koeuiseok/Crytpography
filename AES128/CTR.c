#include "AES.h"
#include<stdio.h>
#include<stdlib.h>

void CTR_plus(unsigned char* CTR, int num) {
	int carry0, carry, i;
	carry0 = num;
	for (i = 15; i >= 0; i--) {
		carry = (CTR[i] + carry0) / 256;
		CTR[i] += carry0 - (carry * 256);
		carry0 = carry;
	}
}


void CTR_add(unsigned char* CTR) {
	int carry0=1, carry=0, i=0;
	for (i = 15; i >= 0; i--) {
		carry = (CTR[i] + carry0) >>8;//처음캐리 계싼과정
		CTR[i] += carry0 - (carry <<8);//ADC
		carry0 = carry; //carry 운반과정
		if (carry0 == 0) break;
	}
}

void AES_CTR_MCT(unsigned char* plaintext, unsigned char* ciphertext, const unsigned char* key, unsigned char* CTR, int round) {
	if (round == 0) {
		return;
	}
	unsigned char Ikey[16] = { 0, };
	unsigned char CTR_128[16] = { 0, };
	memcpy(Ikey, key, 16 * sizeof(unsigned char));
	memcpy(CTR_128, CTR, 16 * sizeof(unsigned char));
	AES_Enc2(CTR_128, ciphertext, Ikey);
	for (int i = 0; i < 16; i++) {
		ciphertext[i] ^= plaintext[i];
	}
	CTR_add(CTR);
	memcpy(plaintext, ciphertext, 16 * sizeof(unsigned char));
	AES_CTR_MCT(plaintext, ciphertext, key, CTR, round - 1);
}


void xor_CTR(unsigned char* CTR, unsigned char* text) {
	for (int i = 0; i < 16; i++) {
		text[i] ^= CTR[i];
	}
}

void AES_CTR(unsigned char* plaintext, unsigned char* ciphertext,unsigned char* key, unsigned char* CTR, int size) {
	unsigned char CTR_128[16] = { 0, };
	unsigned char text_128[16] = { 0, };
	unsigned char key_128[16] = { 0, };
	int h;
	memcpy(key_128, key, 16*sizeof(unsigned char));
	memcpy(CTR_128,CTR,16*sizeof(unsigned char));

	unsigned char cipher_128[16] = { 0, };
	for (int i = 0; i < size/16; i++) {
		printf("\nfirst  ");
		for (int j = 0; j < 16; j++) {
			text_128[j] = plaintext[i * 16 + j];
			printf("%02x", text_128[j]);
		}
		printf("\nbefore  ");
		for (int h = 0; h < 16; h++) {
			printf("%02x", CTR_128[h]);
		}
		AES_Enc2(CTR_128,cipher_128, key);
		printf("\nENC  ");
		for (int h = 0; h < 16; h++) {
			printf("%02x", cipher_128[h]);
		}
		xor_CTR(text_128,cipher_128);
		printf("\nXOR  ");
		for (int h = 0; h < 16; h++) {
			printf("%02x", cipher_128[h]);
		}
		CTR_add(CTR_128);
		printf("\n");
		for (int h = 0; h < 16; h++) {
			printf("%02x",CTR_128[h]);
		}
		for (int h = 0; h < 16; h++) {
			ciphertext[16 * i + h] = cipher_128[h];
		}
	}
}