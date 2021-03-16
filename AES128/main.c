/******************************************************************************
* what is this code? : It makes test response file about request file AES & operation mode
* crypto : AES 128
* support operation mode : ECB CBC CTR
* test : MMT MCT KAT
*
* If you want to make AES128-ECB-MMT response file about AES128-ECB-MMT request file,
* you will define "ECB_MMT" like 'line 20'
*
* If you want to know more imformation, you will contact me :
*
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "AES.h"

#define ECB_MMT   // <- if you want to test other req file, you will change this code 

#if defined(ECB_MMT)
int main() {                //AES_ECB_MMT

	unsigned char key[16] = { 0, };
	unsigned char* plaintext;
	unsigned char* ciphertext;

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;
	int index, data;

	unsigned char IV[16] = { 0, };

	int buf_size = 140;

	err = fopen_s(&req, "REQ/AES128(ECB)MMT.REQ", "rb");
	err1 = fopen_s(&rsp, "RSP\\AES128(ECB)MMT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int j = 0;
	while (j < 10) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			key[i] = RR;
			fprintf(rsp, "%02X", key[i]);
		}


		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		plaintext = (unsigned char*)malloc(16 * (j + 1));
		for (int i = 0; i < 16 * (j + 1); i++) {
			fscanf(req, "%02X", &RR);
			plaintext[i] = RR;
			fprintf(rsp, "%02X", plaintext[i]);
		}
		printf("\nkey = ");
		for (int h = 0; h < 16; h++) {
			printf("%02X", key[h]);

		}printf("\n");
		printf("\nplaintext = ");
		for (int h = 0; h < 16 * (j + 1); h++) {
			printf("%02X", plaintext[h]);
		}
		printf("\n");
		fprintf(rsp, "\nCP = ");
		ciphertext = (unsigned char*)malloc(16 * (j + 1));
		AES_ECB(plaintext, ciphertext, key, 16 * (j + 1));
		for (int i = 0; i < 16 * (j + 1); i++) {
			printf("%02X", ciphertext[i]);
			fprintf(rsp, "%02X", ciphertext[i]);
		}
		printf("\n");
		j++;
		free(plaintext);
		free(ciphertext);

	}
	fclose(req);
	fclose(rsp);
	return 0;
}
#elif defined(CTR_MMT)
int main() {                //AES_CTR_MMT

	unsigned char key[16] = { 0, };
	unsigned char* plaintext;
	unsigned char* ciphertext;
	unsigned char CTR[16] = { 0, };

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;
	int index, data;


	int buf_size = 140;

	err = fopen_s(&req, "REQ/AES128(CTR)MMT.REQ", "rb");
	err1 = fopen_s(&rsp, "RSP\\AES128(CTR)MMT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int j = 0;
	while (j < 10) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			key[i] = RR;
			fprintf(rsp, "%02X", key[i]);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			CTR[i] = RR;
			fprintf(rsp, "%02X", CTR[i]);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		plaintext = (unsigned char*)malloc(16 * (j + 1));
		for (int i = 0; i < 16 * (j + 1); i++) {
			fscanf(req, "%02X", &RR);
			plaintext[i] = RR;
			fprintf(rsp, "%02X", plaintext[i]);
		}
		printf("\nkey = ");
		for (int h = 0; h < 16; h++) {
			printf("%02X", key[h]);

		}printf("\n");
		printf("\nplaintext = ");
		for (int h = 0; h < 16 * (j + 1); h++) {
			printf("%02X", plaintext[h]);
		}

		fprintf(rsp, "\nCP = ");
		ciphertext = (unsigned char*)malloc(16 * (j + 1));
		AES_CTR(plaintext, ciphertext, key, CTR, 16 * (j + 1));
		for (int i = 0; i < 16 * (j + 1); i++) {
			printf("%02X", ciphertext[i]);
			fprintf(rsp, "%02X", ciphertext[i]);
		}
		fprintf(rsp, "\n");
		j++;
		free(plaintext);
		free(ciphertext);

	}
	fclose(req);
	fclose(rsp);
	return 0;
}

#elif defined(CBC_MMT)
int main() {                   //CBC MMT
	unsigned char key[16] = { 0, };
	unsigned char* plaintext;
	unsigned char* ciphertext;

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;
	int index, data;

	unsigned char IV[16] = { 0, };

	int buf_size = 140;

	err = fopen_s(&req, "REQ/AES128(CBC)MMT.REQ", "rb");
	err1 = fopen_s(&rsp, "RSP\\AES128(CBC)MMT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int j = 0;
	while (j < 10) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			key[i] = RR;
			fprintf(rsp, "%02X", key[i]);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			IV[i] = RR;
			fprintf(rsp, "%02X", IV[i]);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		plaintext = (unsigned char*)malloc(16 * (j + 1));
		for (int i = 0; i < 16 * (j + 1); i++) {
			fscanf(req, "%02X", &RR);
			plaintext[i] = RR;
			fprintf(rsp, "%02X", plaintext[i]);
		}
		printf("\nkey = ");
		for (int h = 0; h < 16; h++) {
			printf("%02X", key[h]);

		}printf("\n");
		printf("\nplaintext = ");
		for (int h = 0; h < 16 * (j + 1); h++) {
			printf("%02X", plaintext[h]);
		}
		printf("\n");
		fprintf(rsp, "\nCP = ");
		ciphertext = (unsigned char*)malloc(16 * (j + 1));
		AES_CBC(plaintext, ciphertext, key, IV, 16 * (j + 1));
		for (int i = 0; i < 16 * (j + 1); i++) {
			printf("%02X", ciphertext[i]);
			fprintf(rsp, "%02X", ciphertext[i]);
		}
		printf("\n");
		j++;
		free(plaintext);
		free(ciphertext);

	}
	fclose(req);
	fclose(rsp);
	return 0;
}

#elif defined(CTR_KAT)
int main() {       //CTR_KAT

	unsigned char key[16] = { 0, };
	unsigned char plaintext[16] = { 0, };
	unsigned char ciphertext[16] = { 0, };

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;
	int index, data;

	unsigned char CTR[16] = { 0, };

	int buf_size = 140;

	err = fopen_s(&req, "REQ/AES128(CTR)KAT.REQ", "rb");
	err1 = fopen_s(&rsp, "RSP\\AES128(CTR)KAT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int j = 0;
	while (j <= 275) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			key[i] = RR;
			fprintf(rsp, "%02X", key[i]);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			CTR[i] = RR;
			fprintf(rsp, "%02X", CTR[i]);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			plaintext[i] = RR;
			fprintf(rsp, "%02X", plaintext[i]);
		}
		printf("\nkey = ");
		for (int h = 0; h < 16; h++) {
			printf("%02X", key[h]);

		}printf("\n");
		printf("\nplaintext = ");
		for (int h = 0; h < 16; h++) {
			printf("%02X", plaintext[h]);
		}
		printf("\n");
		fprintf(rsp, "\nCP = ");
		AES_CTR(plaintext, ciphertext, key, CTR, 16);
		for (int i = 0; i < 16; i++) {
			printf("%02X", ciphertext[i]);
			fprintf(rsp, "%02X", ciphertext[i]);
		}
		printf("\n");
		j++;

	}
	fclose(req);
	fclose(rsp);
	return 0;
}

#elif defined(ECB_KAT)
int main() {

	unsigned char key[16] = { 0, };
	unsigned char plaintext[16] = { 0, };
	unsigned char ciphertext[16] = { 0, };

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;
	int index, data;

	unsigned char IV[16] = { 0, };

	int buf_size = 140;

	err = fopen_s(&req, "REQ/AES128(ECB)KAT.REQ", "rb");
	err1 = fopen_s(&rsp, "RSP\\AES128(ECB)KAT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int j = 0;
	while (j <= 275) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			key[i] = RR;
			fprintf(rsp, "%02X", key[i]);
		}


		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			plaintext[i] = RR;
			fprintf(rsp, "%02X", plaintext[i]);
		}
		printf("\nkey = ");
		for (int h = 0; h < 16; h++) {
			printf("%02X", key[h]);

		}printf("\n");
		printf("\nplaintext = ");
		for (int h = 0; h < 16; h++) {
			printf("%02X", plaintext[h]);
		}
		printf("\n");
		fprintf(rsp, "\nCP = ");
		AES_ECB(plaintext, ciphertext, key, 16);
		for (int i = 0; i < 16; i++) {
			printf("%02X", ciphertext[i]);
			fprintf(rsp, "%02X", ciphertext[i]);
		}
		printf("\n");
		j++;

	}
	fclose(req);
	fclose(rsp);
	return 0;
}

#elif defined(CBC_KAT)
int main() {        //AES CBC KAT

	unsigned char key[16] = { 0, };
	unsigned char plaintext[16] = { 0, };
	unsigned char ciphertext[16] = { 0, };

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;
	int index, data;

	unsigned char IV[16] = { 0, };

	int buf_size = 140;

	err = fopen_s(&req, "REQ/AES128(CBC)KAT.REQ", "rb");
	err1 = fopen_s(&rsp, "RSP\\AES128(CBC)KAT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int j = 0;
	while (j <= 275) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			key[i] = RR;
			fprintf(rsp, "%02X", key[i]);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			IV[i] = RR;
			fprintf(rsp, "%02X", IV[i]);
		}

		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (int i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			plaintext[i] = RR;
			fprintf(rsp, "%02X", plaintext[i]);
		}
		printf("\nkey = ");
		for (int h = 0; h < 16; h++) {
			printf("%02X", key[h]);

		}printf("\n");
		printf("\nplaintext = ");
		for (int h = 0; h < 16; h++) {
			printf("%02X", plaintext[h]);
		}
		printf("\n");
		fprintf(rsp, "\nCP = ");
		AES_CBC(plaintext, ciphertext, key, IV, 16);
		for (int i = 0; i < 16; i++) {
			printf("%02X", ciphertext[i]);
			fprintf(rsp, "%02X", ciphertext[i]);
		}
		printf("\n");
		j++;

	}
	fclose(req);
	fclose(rsp);
	return 0;
}

#elif defined(ECB_MCT)
int main() {             //ECB MCT

	unsigned char key[16] = { 0, };
	unsigned char plaintext[16] = { 0, };
	unsigned char ciphertext[16] = { 0, };

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;

	err = fopen_s(&req, "REQ/AES128(ECB)MCT.REQ", "rb");
	err1 = fopen_s(&rsp, "RSP\\AES128(ECB)MCT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int i, j, h, w = 0;
	while (w < 100) {
		fprintf(rsp, "COUNT = %d", w);
		if (w == 0) {
			fscanf(req, "%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (int i = 0; i < 16; i++) {
				fscanf(req, "%02X", &RR);
				key[i] = RR;
				fprintf(rsp, "%02X", key[i]);
			}

			fscanf(req, "%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (int i = 0; i < 16; i++) {
				fscanf(req, "%02X", &RR);
				plaintext[i] = RR;
				fprintf(rsp, "%02X", plaintext[i]);
			}
		}
		else {
			fprintf(rsp, "\nKEY = ");
			for (i = 0; i < 16; i++) {
				key[i] ^= ciphertext[i];
				fprintf(rsp, "%02X", key[i]);
			}
			fprintf(rsp, "\nPT = ");
			for (i = 0; i < 16; i++) {
				fprintf(rsp, "%02X", ciphertext[i]);
			}
		}

		for (j = 0; j < 1000; j++) {
			AES_ECB(plaintext, ciphertext, key, 16);
			for (int a = 0; a < 16; a++) {
				plaintext[a] = ciphertext[a];
			}
		}

		fprintf(rsp, "\nCT = ");
		for (h = 0; h < 16; h++) {
			printf("%02X", ciphertext[h]);
			fprintf(rsp, "%02X", ciphertext[h]);
		}
		fprintf(rsp, "\n");
		w++;
	}
	fclose(req);
	fclose(rsp);
	return 0;
}

#elif defined(CBC_MCT)
int main() {             //CBC MCT

	unsigned char key[16] = { 0, };
	unsigned char plaintext[16] = { 0, };
	unsigned char ciphertext[16] = { 0, };
	unsigned char IV[16] = { 0, };
	unsigned char fore_ciphertext[16] = { 0, };

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;

	err = fopen_s(&req, "REQ/AES128(CBC)MCT.REQ", "rb");
	err1 = fopen_s(&rsp, "RSP\\AES128(CBC)MCT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int i, j, h, w = 0;
	fprintf(rsp, "COUNT = 0");
	fscanf(req, "%s = ", tmp);
	fprintf(rsp, "\n%s = ", tmp);
	for (int i = 0; i < 16; i++) {
		fscanf(req, "%02X", &RR);
		key[i] = RR;
		fprintf(rsp, "%02X", key[i]);
	}

	fscanf(req, "%s = ", tmp);
	fprintf(rsp, "\n%s = ", tmp);
	for (int i = 0; i < 16; i++) {
		fscanf(req, "%02X", &RR);
		IV[i] = RR;
		fprintf(rsp, "%02X", IV[i]);
	}

	fscanf(req, "%s = ", tmp);
	fprintf(rsp, "\n%s = ", tmp);
	for (int i = 0; i < 16; i++) {
		fscanf(req, "%02X", &RR);
		plaintext[i] = RR;
		fprintf(rsp, "%02X", plaintext[i]);
	}
	unsigned char Ikey[16] = { 0, };
	while (w < 100) {
		if (w == 0) {
			fprintf(rsp, "\nCOUNT = %d", w);
		}
		else {
			fprintf(rsp, "\nKEY = ");
			for (i = 0; i < 16; i++) {
				Ikey[i] = key[i];
				key[i] ^= ciphertext[i];
				fprintf(rsp, "%02X", key[i]);
			}

			fprintf(rsp, "\nIV = ", tmp);
			for (int i = 0; i < 16; i++) {
				IV[i] = ciphertext[i];
				fprintf(rsp, "%02X", IV[i]);
			}

			fprintf(rsp, "\nPT = ");
			for (i = 0; i < 16; i++) {
				fprintf(rsp, "%02X", fore_ciphertext[i]);
				plaintext[i] = fore_ciphertext[i];
			}
		}
		for (int n = 0; n < 16; n++) {
			ciphertext[n] = plaintext[n];
		}

		for (j = 0; j < 1000; j++) {
			for (i = 0; i < 16; i++) {
				fore_ciphertext[i] = ciphertext[i];
			}
			AES_CBC(plaintext, ciphertext, key, IV, 16);
			for (i = 0; i < 16; i++) {
				plaintext[i] = fore_ciphertext[i];
				IV[i] = ciphertext[i];
			}
		}

		fprintf(rsp, "\nCT = ");
		for (h = 0; h < 16; h++) {
			fprintf(rsp, "%02X", ciphertext[h]);
		}
		fprintf(rsp, "\n");
		w++;
	}
	fclose(req);
	fclose(rsp);
	return 0;
}

#elif defined(CTR_MCT)
int main() {             //CTR MCT

	unsigned char key[16] = { 0, };
	unsigned char plaintext[16] = { 0, };
	unsigned char ciphertext[16] = { 0, };
	unsigned char IV[16] = { 0, };
	unsigned char fore_ciphertext[16] = { 0, };

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;

	err = fopen_s(&req, "REQ/AES128(CTR)MCT.REQ", "rb");
	err1 = fopen_s(&rsp, "RSP\\AES128(CTR)MCT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int i, j, h, w = 0;
	while (w < 100) {
		fprintf(rsp, "\nCOUNT = %d", w);
		if (w == 0) {
			fscanf(req, "%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (int i = 0; i < 16; i++) {
				fscanf(req, "%02X", &RR);
				key[i] = RR;
				fprintf(rsp, "%02X", key[i]);
			}

			fscanf(req, "%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (int i = 0; i < 16; i++) {
				fscanf(req, "%02X", &RR);
				IV[i] = RR;
				fprintf(rsp, "%02X", IV[i]);
			}

			fscanf(req, "%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (int i = 0; i < 16; i++) {
				fscanf(req, "%02X", &RR);
				plaintext[i] = RR;
				fprintf(rsp, "%02X", plaintext[i]);
			}
		}
		else {

			fprintf(rsp, "\nKEY = ");
			for (i = 0; i < 16; i++) {
				key[i] ^= ciphertext[i];
				fprintf(rsp, "%02X", key[i]);
			}

			fprintf(rsp, "\nCTR = ");
			for (i = 0; i < 16; i++) {
				fprintf(rsp, "%02X", IV[i]);
			}

			fprintf(rsp, "\nPT = ");
			for (i = 0; i < 16; i++) {
				fprintf(rsp, "%02X", plaintext[i]);
			}

		}

		for (j = 0; j < 1000; j++) {
			AES_CBC(plaintext, ciphertext, key, IV, 16);
			CTR_plus(IV, 1);
			for (int x = 0; x < 16; x++) {
				plaintext[x] = ciphertext[x];
			}
		}

		fprintf(rsp, "\nCT = ");
		for (h = 0; h < 16; h++) {
			printf("%x", ciphertext[h]);
			fprintf(rsp, "%02X", ciphertext[h]);
		}
		fprintf(rsp, "\n");
		w++;
	}
	fclose(req);
	fclose(rsp);
	return 0;
}
#endif

/*
int main() {                //AES_CTR_MMT

	unsigned char key[16] = { 0, };
	unsigned char* plaintext;
	unsigned char* ciphertext;
	unsigned char CTR[16] = { 0, };

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;
	int index, data;
	int buf_size = 140;

	err = fopen_s(&req, "AES128(CTR)MMT.REQ", "rb");
	err1 = fopen_s(&rsp, "AES128(CTR)MMT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int j = 0;
	while (j < 10) {
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		int i;
		for (i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			key[i] = RR;
			fprintf(rsp, "%02X", key[i]);
		}
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (i = 0; i < 16; i++) {
			fscanf(req, "%02X", &RR);
			CTR[i] = RR;
			fprintf(rsp, "%02X", CTR[i]);
		}
		plaintext = (unsigned char*)realloc(16 * (j + 1));
		fscanf(req, "%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		for (i = 0; i < 16*(j+1); i++) {
			fscanf(req, "%02X", &RR);
			plaintext[i] = RR;
			fprintf(rsp, "%02X", plaintext[i]);
		}
		ciphertext = (unsigned char*)malloc(16 * (j + 1));
		fprintf(rsp, "\nCP = ");
		AES_CTR(plaintext, ciphertext, key, CTR, 16 * (j + 1));
		for (int i = 0; i < 16 * (j + 1); i++) {
			printf("%02X", ciphertext[i]);
			fprintf(rsp, "%02X", ciphertext[i]);
		}
		fprintf(rsp, "\n");
		j++;
		free(plaintext);
		free(ciphertext);

	}
	fclose(req);
	fclose(rsp);
	return 0;
}


int main() {             //CBC MCT 22222

	unsigned char key[16] = { 0, };
	unsigned char plaintext[16] = { 0, };
	unsigned char ciphertext[16] = { 0, };
	unsigned char IV[16] = { 0, };
	unsigned char fore_ciphertext[16] = { 0, };

	errno_t err, err1;  //파일 입력
	FILE* req, * rsp;

	err = fopen_s(&req, "AES128(CBC)MCT.REQ", "rb");
	err1 = fopen_s(&rsp, "AES128(CBC)MCT.RSP", "w");
	if (err == 0) {
		puts("파일 오픈 성공!");
	}
	else {
		puts("파일 오픈 실패!\n");
		return -1;
	}
	unsigned char tmp[100];
	unsigned int RR = 0;
	int i, j, h, w = 0;

	fscanf(req, "%s = ", tmp);
	for (int i = 0; i < 16; i++) {
		fscanf(req, "%02X", &RR);
		key[i] = RR;
	}

	fscanf(req, "%s = ", tmp);
	for (int i = 0; i < 16; i++) {
		fscanf(req, "%02X", &RR);
		IV[i] = RR;
	}

	fscanf(req, "%s = ", tmp);
	for (int i = 0; i < 16; i++) {
		fscanf(req, "%02X", &RR);
		plaintext[i] = RR;
	}

	while (w < 100) {
		fprintf(rsp, "COUNT = %d",w);

		fprintf(rsp, "\nKEY = ");
		for (int i = 0; i < 16; i++) {
			fprintf(rsp, "%02X", key[i]);
		}

		fprintf(rsp, "\nIV = ");
		for (int i = 0; i < 16; i++) {
			fprintf(rsp, "%02X", IV[i]);
		}

		fprintf(rsp, "\nPT = ");
		for (int i = 0; i < 16; i++) {
			fprintf(rsp, "%02X", plaintext[i]);
		}
		printf("\nbefore key = ");
		for (int i = 0; i < 16; i++) {
			printf("%02X", key[i]);
		}
		printf("\n");
		AES_CBC_MCT(plaintext, ciphertext, key, IV, 1000);
		printf("after key = ");
		for (int i = 0; i < 16; i++) {
			printf("%02X", key[i]);
		}
		printf("\n");
		fprintf(rsp, "\nCT = ");
		for (h = 0; h < 16; h++) {
			fprintf(rsp, "%02X", ciphertext[h]);
			key[h] ^= IV[h];
		}
		fprintf(rsp, "\n");
		w++;
	}
	fclose(req);
	fclose(rsp);
	return 0;
}
*/

