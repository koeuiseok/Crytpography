#include "AES.h"
#include<stdio.h>
#include<stdlib.h>


void xor_IV(unsigned char* text, unsigned char* CB) {
	for (int i = 0; i < 16; i++) {
		text[i] ^= CB[i];
	}
}



void AES_CBC(unsigned char* plaintext, unsigned char* ciphertext,const unsigned char* key, unsigned char* IV, int size) {
	unsigned char text_128[16] = { 0, };
	unsigned char CB[16] = { 0, };
	unsigned char key1[16] = { 0, };
	for (int i = 0; i < size/16; i++) {
		for (int j = 0; j < 16; j++) {
			if (i == 0) {
				CB[j] = IV[j];
			}
			else {
				CB[j] = ciphertext[16*(i-1)+j];
			}
			key1[j] = key[j];
			text_128[j] = plaintext[16*i+j];
		}
		xor_IV(text_128, CB);
		
		AES_Enc(text_128, key1);

		for (int h = 0; h < 16; h++) {
			ciphertext[16 * i + h] = text_128[h];
		}
	}
}

void AES_CBC_MCT(unsigned char* plaintext, unsigned char* ciphertext, const unsigned char* key, unsigned char* IV, int round) {
	if (round == 0) {
		return;
	}
	unsigned char Ikey[16] = { 0, };
	memcpy(Ikey, key, 16 * sizeof(unsigned char));
	for (int i = 0; i < 16; i++) {
		plaintext[i] ^= IV[i];
	}
	AES_Enc2(plaintext, ciphertext, Ikey);
	memcpy(plaintext, IV, 16 * sizeof(unsigned char));
	memcpy(IV, ciphertext, 16 * sizeof(unsigned char));
	AES_CBC_MCT(plaintext, ciphertext, key, IV, round - 1);
}

