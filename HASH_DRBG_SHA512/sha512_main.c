#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SHA512/SHA512.h"

#define speed_test
//#define Monte
//#define LongMsg
//#define ShortMsg

#if defined(speed_test)
__int64 cpucycle(void) { return __rdtsc(); }

int main() {

	unsigned long long cycles, cycles1, cycles2, cycle = 0;
	BYTE pszMessage[3] = { 0x61,0x62,0x63 };
	BYTE pszDigest[64] = { 0, };
	ULONGLONG uPlaintext = 3;

	cycles1 = cpucycle();
	for (int i = 0; i < 10000; i++) {
		SHA512_Encrpyt(pszMessage, uPlaintext, pszDigest);
	}
	cycles2 = cpucycle();
	cycles = cycles2 - cycles1;
	printf("cycles : %10lld", cycles / 10000);
	printf("\n");

	for (int j = 0; j < 64; j++) {
		printf("%02x\t", pszDigest[j]);
	}

	return 0;
}



#elif defined(Monte)
int main() {              //Monte 512
	FILE* req, * rsp;
	req = fopen("SHA2(512)Monte.REQ", "rb");
	rsp = fopen("SHA2(512)Monte.RSP", "w");
	if (rsp == NULL) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == NULL) {
		printf("req open 실패!!\n");
		return 1;
	}
	BYTE seed[64] = { 0, };
	BYTE pszDigest[64] = { 0, };
	BYTE MD_n1[64] = { 0, };
	BYTE MD_n2[64] = { 0, };
	BYTE MD_n3[64] = { 0, };
	BYTE MD[192] = { 0, };
	UCHAR tmp[100];
	UINT RR = 0;
	UINT round = 0;  //Len 길이 임시저장 예정
	int i = 0;
	fscanf(req, "%s = ", tmp);
	fprintf(rsp, "%s = ", tmp);
	fscanf(req, "%02x", &RR);
	fprintf(rsp, "%02x", RR);
	fprintf(rsp, "\n\n");
	fscanf(req, "%s = ", tmp);
	fprintf(rsp, "%s = ", tmp);
	for (int j = 0; j < 64; j++) {
		fscanf(req, "%02x", &RR);
		seed[j] = RR;
		fprintf(rsp, "%02x", seed[j]);  

	}
	fprintf(rsp, "\n");
	while (i < 100) {
		for (int j = 0; j < 64; j++) {
			MD_n1[j] = seed[j];
			MD_n2[j] = seed[j];
			MD_n3[j] = seed[j];
		}
		fprintf(rsp, "COUNT = %d", i);
		i++;

		for (int w = 0; w < 1000; w++) {
			for (int y = 0; y < 64; y++) {
				MD[y] = MD_n3[y];
				MD[y + 64] = MD_n2[y];
				MD[y + 128] = MD_n1[y];
			}
			SHA512_Encrpyt(MD, 192, pszDigest);
			memcpy(MD_n3, MD_n2, 64 * sizeof(BYTE));
			memcpy(MD_n2, MD_n1, 64 * sizeof(BYTE));
			memcpy(MD_n1, pszDigest, 64 * sizeof(BYTE));
		}
		memcpy(seed, pszDigest, 64 * sizeof(BYTE));
		fprintf(rsp, "\nMD = ");
		for (int w = 0; w < 64; w++) {
			fprintf(rsp, "%02x", pszDigest[w]);   //msg = %02x 입출력
		}
		fprintf(rsp, "\n\n");
	}

	fclose(rsp);
	fclose(req);
	return 0;
}

#elif defined(LongMsg)
int main() {            //LongMsg SHA512
	FILE* req, * rsp;
	req = fopen("SHA2(512)LongMsg.REQ", "rb");
	rsp = fopen("SHA2(512)LongMsg.RSP", "w");
	if (rsp == NULL) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == NULL) {
		printf("req open 실패!!\n");
		return 1;
	}
	BYTE* pszMessage = malloc(63 * sizeof(BYTE));
	BYTE pszDigest[64] = { 0, };
	UCHAR tmp[100];
	UINT RR = 0;
	UINT round = 0;  //Len 길이 임시저장 예정
	int i = 0;
	int uPlainTextLen = 0;
	fscanf(req, "%s = ", tmp);
	fprintf(rsp, "%s = ", tmp);
	fscanf(req, "%02x", &RR);
	fprintf(rsp, "%02x", RR);
	fprintf(rsp, "\n\n");
	while (i < 128) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);  //Len = %d 입출력
		round = RR;
		uPlainTextLen = round >> 3;
		i++;
		pszMessage = (BYTE*)realloc(pszMessage, (uPlainTextLen) * sizeof(BYTE));
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int j = 0; j < uPlainTextLen; j++) {
			fscanf(req, "%02x", &RR);
			pszMessage[j] = RR;
			fprintf(rsp, "%02x", pszMessage[j]);  
		}
		printf("\nDigest = ");
		SHA512_Encrpyt(pszMessage, uPlainTextLen, pszDigest);
		fprintf(rsp, "\nMD = ");
		for (int w = 0; w < 64; w++) {
			fprintf(rsp, "%02x", pszDigest[w]);  
			printf("%02x", pszDigest[w]);
		}
		fprintf(rsp, "\n\n");
	}

	fclose(rsp);
	fclose(req);
	return 0;
}

#elif defined(ShortMsg)
int main() {            //ShortMsg SHA512
	FILE* req, * rsp;
	req = fopen("SHA2(512)ShortMsg.REQ", "rb");
	rsp = fopen("SHA2(512)ShortMsg.RSP", "w");
	if (rsp == NULL) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == NULL) {
		printf("req open 실패!!\n");
		return 1;
	}
	BYTE* pszMessage = malloc(sizeof(BYTE));
	BYTE pszDigest[64] = { 0, };
	UCHAR tmp[100];
	int RR = 0;
	UINT length = 0;
	int i = 0, j = 0;
	int uPlainTextLen = 0;
	fscanf(req, "%s = ", tmp);
	fprintf(rsp, "%s = ", tmp);
	fscanf(req, "%02x", &RR);
	fprintf(rsp, "%02x", RR);

	for (i = 0; i <= 128; i++) {
		fprintf(rsp, "\n\n");
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "%s = ", tmp);
		fscanf(req, "%d", &RR);
		fprintf(rsp, "%d", RR);
		uPlainTextLen = RR >> 3;
		if (RR == 0) { RR += 8; }
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		printf("\nlen = %d\n", RR);
		length = RR >> 3;
		pszMessage = (BYTE*)realloc(pszMessage, sizeof(BYTE) * length);
		for (j = 0; j < length; j++) {
			fscanf(req, "%02x", &RR);
			pszMessage[j] = RR;
			fprintf(rsp, "%02x", pszMessage[j]);
			printf("%02x", pszMessage[j]);
		}

		SHA512_Encrpyt(pszMessage, uPlainTextLen, pszDigest);
		
		fprintf(rsp, "\nMD = ");
		printf("\nMD = ");
		for (int w = 0; w < 64; w++) {
			fprintf(rsp, "%02x", pszDigest[w]);
			printf("%02x", pszDigest[w]);
		}
	}
	fclose(rsp);
	fclose(req);
	return 0;
}
#endif