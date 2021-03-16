#include "AES.h"
#include<stdio.h>
#include<stdlib.h>

void AES_ECB(unsigned char* plaintext, unsigned char* ciphertext,unsigned char* key, int size) {
	unsigned char Ikey[16] = { 0, };
	unsigned char text_128[16] = { 0, };
	for (int i = 0; i < size/16; i++) {
		for (int j = 0; j < 16; j++) {
			text_128[j] = plaintext[i * 16 + j];
			Ikey[j] = key[j];
		}

		AES_Enc(text_128, Ikey);
		for (int h = 0; h < 16; h++) {
			ciphertext[16*i+h] = text_128[h];
		}
	}
}