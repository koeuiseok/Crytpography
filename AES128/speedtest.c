//FOR SPEED TEST HAHA

/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "AES.h"

__int64 cpucycle(void) { return __rdtsc(); }

unsigned char plaintext[16] = { 0x21,0x1e,0x13,0x12,0x22,0x2e,0xd2,0xa3,0xab,0x17,0x15,0x88,0x09,0x1f,0x41,0x31 };
unsigned char key[16] = { 0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c };
unsigned char IV[16] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 ,0x00,0x00,0x00,0x00 ,0x00,0x00,0x00,0x00 };

int main() {
	int size = sizeof(plaintext) / sizeof(char);
	unsigned long long cycles, cycles1, cycles2, cycle = 0;

	cycles1 = cpucycle();
	for (int i = 0; i < 10000; i++) {
		AES_Enc(plaintext,key);
	}
	cycles2 = cpucycle();
	cycles = cycles2 - cycles1;
	printf("cycles : %10lld", cycles / 10000);
	printf("\n");

	for (int j = 0; j < 16; j++) {
		printf("%x", plaintext[j]);
	}

	return 0;
}
*/