#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SHA512/SHA512.h"
#include "DRBG/DRBG.h"

#define speed_test
// #define test_drbg_use_pr
// #define test_drbg_no_pr


#if defined(speed_test)
__int64 cpucycle(void) { return __rdtsc(); }

int main() {

	unsigned long long cycles, cycles1, cycles2, cycle = 0;
	Hash_DRBG_CTX drbg_ctx = { {0x00,},0x00, };
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
	cycles1 = cpucycle();
	drbg_ctx.prediction_resistance_flag = 0;
	for (int i = 0; i < 10000; i++) {
		Instant_Fnc(&drbg_ctx, entropy, entropy_len, Nonce, Noncelen, personal_input, per_len);
		reseed_fnc(&drbg_ctx, entropy_input, entropy_len, add_input, add_len);
		generate_fnc(&drbg_ctx, entropy_reseed, entropy_len, add_input, add_len, returnedbits, returned_len);
		generate_fnc(&drbg_ctx, entropy_reseed, entropy_len, add_input, add_len, returnedbits, returned_len);
	}

	cycles2 = cpucycle();
	cycles = cycles2 - cycles1;
	printf("cycles : %10lld", cycles / 10000);
	printf("\n");
	for (int i = 0; i < returned_len; i++)
		printf("%02X", returnedbits[i]);
	return 0;
}

#elif(test_drbg_use_pr)
int main() // HASH_DRBG use PR
{
	FILE* req, * rsp;
	req = fopen("KAT_REQ/HASH_DRBG(SHA512(use PR))_KAT.REQ", "rb");
	rsp = fopen("HASH_DRBG(SHA512(use PR))_KAT.RSP", "w");
	if (rsp == NULL) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == NULL) {
		printf("req open 실패!!\n");
		return 1;
	}
	Hash_DRBG_CTX drbg_ctx = { {0x00,},0x00, };
	unsigned char tmp[100] = { 0x00, };
	unsigned int RR = 0;
	unsigned int RX = 0;
	unsigned int a = 0;
	for (unsigned int x = 0; x < 4; x++) {
		//=========================================================기본 정보
		a = fscanf(req, "%s", tmp);
		printf("%s", tmp);
		fprintf(rsp, "\n%s", tmp);

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
		a = fscanf(req, "%d]", &RR);
		unsigned int entropy_Input_len = RR;
		unsigned int entropy_input_len_byte = entropy_Input_len >> 3;
		printf("%d]", entropy_Input_len);
		fprintf(rsp, "%d]", RR);

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%d]", &RR);
		unsigned int nonce_len = RR;
		unsigned int nonce_len_byte = RR >> 3;
		printf("%d]", nonce_len);
		fprintf(rsp, "%d]", RR);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &RR);
		unsigned int personal_string_len = RR;
		unsigned int personal_string_len_byte = RR >> 3;
		printf("%d]", personal_string_len);
		fprintf(rsp, "%d]", RR);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &RR);
		unsigned int add_input_len = RR;
		unsigned int add_input_len_byte = RR >> 3;
		printf("%d]", add_input_len);
		fprintf(rsp, "%d]", RR);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &RR);
		unsigned int outlen = RR;
		unsigned int outlen_byte = RR >> 3;
		printf("%d]", outlen);
		fprintf(rsp, "%d]", RR);
		//==============================================시작 정보를 이용한 기본 선언
		unsigned char* EntropyInput = NULL;
		EntropyInput = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* Nonce = NULL;
		Nonce = (unsigned char*)calloc(nonce_len_byte, sizeof(unsigned char));
		unsigned char* personal_string = NULL;
		personal_string = (unsigned char*)calloc(personal_string_len_byte, sizeof(unsigned char));
		unsigned char* additional_input_reseed = NULL;
		additional_input_reseed = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input1 = NULL;
		additional_input1=(unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input2 = NULL;
		additional_input2 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* EntropyPR1 = NULL;
		EntropyPR1 = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* EntropyPR2 = NULL;
		EntropyPR2 = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* output = NULL;
		output = (unsigned char*)calloc(outlen_byte, sizeof(unsigned char));
		//====================================================처음 부분 시작
		for (unsigned int i = 0; i < 15; i++) {
			fscanf(req, "%s = ", tmp);
			printf("\n\n%s = ", tmp);
			fprintf(rsp, "\n\n%s = ", tmp);
			fscanf(req, "%d", &RR);
			printf("%d", RR);
			fprintf(rsp, "%d", RR);   
			RR = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02X", &RX);
				EntropyInput[w] = RX;
				printf("%02X", RX);
				fprintf(rsp, "%02X", RX);
			}
			RX = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < nonce_len_byte; w++) {
				fscanf(req, "%02X", &RX);
				Nonce[w] = RX;
				printf("%02X", RX);
				fprintf(rsp, "%02X", RX);
			}
			RX = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < personal_string_len_byte; w++) {
				fscanf(req, "%02X", &RX);
				personal_string[w] = RX;
				printf("%02X", RX);
				fprintf(rsp, "%02X", RX);
			}
			RX = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02X", &RX);
				EntropyPR1[w] = RX;
				printf("%02X", RX);
				fprintf(rsp, "%02X", RX);
			}
			RX = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
		
			for (unsigned int w = 0; w < add_input_len_byte; w++) {
				fscanf(req, "%02X", &RX);
				additional_input1[w] = RX;
				printf("%02X", RX);
				fprintf(rsp, "%02X", RX);
			}
			RX = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02X", &RX);
				EntropyPR2[w] = RX;
				printf("%02X", RX);
				fprintf(rsp, "%02X", RX);
			}
			RX = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (add_input_len_byte != 0) {
				for (unsigned int w = 0; w < add_input_len_byte; w++) {
					fscanf(req, "%02X", &RX);
					additional_input2[w] = RX;
					printf("%02X", RX);
					fprintf(rsp, "%02X", RX);
				}
			}
			RX = 0;
			fprintf(rsp, "\nReturnedBitsLen = ");
			printf("\nReturnedBitsLen = ");
			Instant_Fnc(&drbg_ctx, EntropyInput, entropy_input_len_byte, Nonce, nonce_len_byte, personal_string, personal_string_len_byte);
			generate_fnc(&drbg_ctx, EntropyPR1, entropy_input_len_byte, additional_input1, add_input_len_byte, output, outlen_byte);
			generate_fnc(&drbg_ctx, EntropyPR2, entropy_input_len_byte, additional_input2, add_input_len_byte, output, outlen_byte);
			for (unsigned int w = 0; w < outlen_byte; w++) {
				printf("%02X", output[w]);
				fprintf(rsp, "%02X", output[w]);
			}
			RX = 0;
			hash_drbg_ctx_free_use_p(&drbg_ctx);

		}
		free(EntropyInput);
		free(Nonce);
		free(personal_string);
		free(additional_input_reseed);
		free(additional_input1);
		free(additional_input2);
		free(EntropyPR1);
		free(EntropyPR2);
		free(output);
		fprintf(rsp, "\n");
	}
	fclose(rsp);
	fclose(req);
	return 0;
}


#elif(test_drbg_no_pr)


int main() // HASH_DRBG no PR
{
	FILE* req, *rsp;
	req = fopen("KAT_REQ/HASH_DRBG(SHA512(no PR))_KAT.REQ", "rb");
	rsp = fopen("HASH_DRBG(SHA512(no PR))_KAT.RSP", "w");
	if (rsp == NULL) {
		printf("rsp open 실패!!\n");
		return 1;
	}
	if (req == NULL) {
		printf("req open 실패!!\n");
		return 1;
	}
	Hash_DRBG_CTX drbg_ctx = { {0x00,},0x00, };
	unsigned char tmp[100] = { 0x00, };
	unsigned int RR=0;
	unsigned int RX = 0;
	unsigned int a = 0;
	for (unsigned int x = 0; x < 4; x++) {
		//=========================================================기본 정보
		a = fscanf(req, "%s", tmp);
		printf("%s", tmp);
		fprintf(rsp, "%s", tmp);

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
		a = fscanf(req, "%d]", &RR);
		unsigned int entropy_Input_len = RR;
		unsigned int entropy_input_len_byte = entropy_Input_len >> 3;
		printf("%d]", entropy_Input_len);
		fprintf(rsp, "%d]", RR);

		a = fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		a = fscanf(req, "%d]", &RR);
		unsigned int nonce_len = RR;
		unsigned int nonce_len_byte = RR >> 3;
		printf("%d]", nonce_len);
		fprintf(rsp, "%d]", RR);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &RR);
		unsigned int personal_string_len = RR;
		unsigned int personal_string_len_byte = RR >> 3;
		printf("%d]", personal_string_len);
		fprintf(rsp, "%d]", RR);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &RR);
		unsigned int add_input_len = RR;
		unsigned int add_input_len_byte = RR >> 3;
		printf("%d]", add_input_len);
		fprintf(rsp, "%d]", RR);

		fscanf(req, "%s = ", tmp);
		printf("\n%s = ", tmp);
		fprintf(rsp, "\n%s = ", tmp);
		fscanf(req, "%d]", &RR);
		unsigned int outlen = RR;
		unsigned int outlen_byte = RR >> 3;
		printf("%d]", outlen);
		fprintf(rsp, "%d]", RR);
		//==============================================시작 정보를 이용한 기본 선언
		unsigned char* EntropyInput = NULL;
		EntropyInput = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* Nonce = NULL;
		Nonce = (unsigned char*)calloc(nonce_len_byte, sizeof(unsigned char));
		unsigned char* personal_string = NULL;
		personal_string = (unsigned char*)calloc(personal_string_len_byte, sizeof(unsigned char));
		unsigned char* EntropyreseedInput = NULL;
		EntropyreseedInput = (unsigned char*)calloc(entropy_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input_reseed = NULL;
		additional_input_reseed = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input1 = NULL;
		additional_input1 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
		unsigned char* additional_input2 = NULL;
		additional_input2 = (unsigned char*)calloc(add_input_len_byte, sizeof(unsigned char));
	
		unsigned char* output = NULL;
		output = (unsigned char*)calloc(outlen_byte, sizeof(unsigned char));
		//====================================================처음 부분 시작
		for (unsigned int i = 0; i < 15; i++) {
			RR = 0;
			fscanf(req, "%s = ", tmp);
			printf("\n\n%s = ", tmp);
			fprintf(rsp, "\n\n%s = ", tmp);
			fscanf(req, "%d", &RR);
			printf("%d", RR);
			fprintf(rsp, "%d", RR);   
			RR = 0;

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02X", &RX);
				EntropyInput[w] = RX;
				printf("%02X", EntropyInput[w]);
				fprintf(rsp, "%02X", EntropyInput[w]);
			}
			
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < nonce_len_byte; w++) {
				fscanf(req, "%02X", &RX);
				Nonce[w] = RX;
				printf("%02X", Nonce[w]);
				fprintf(rsp, "%02X", Nonce[w]);
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (personal_string_len_byte != 0) {
				for (unsigned int w = 0; w < personal_string_len_byte; w++) {
					fscanf(req, "%02X", &RX);
					personal_string[w] = RX;
					printf("%02X", personal_string[w]);
					fprintf(rsp, "%02X", personal_string[w]);
				}
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			for (unsigned int w = 0; w < entropy_input_len_byte; w++) {
				fscanf(req, "%02X", &RX);
				EntropyreseedInput[w] = RX;
				printf("%02X", EntropyreseedInput[w]);
				fprintf(rsp, "%02X", RX);
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
		
			for (unsigned int w = 0; w < add_input_len_byte; w++) {
				fscanf(req, "%02X", &RX);
				additional_input_reseed[w] = RX;
				printf("%02X", additional_input_reseed[w]);
				fprintf(rsp, "%02X", RX);
			}

			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (add_input_len_byte != 0) {
				for (unsigned int w = 0; w < add_input_len_byte; w++) {
					fscanf(req, "%02X", &RX);
					additional_input1[w] = RX;
					printf("%02X", additional_input1[w]);
					fprintf(rsp, "%02X", RX);
				}
			}
			fscanf(req, "%s = ", tmp);
			printf("\n%s = ", tmp);
			fprintf(rsp, "\n%s = ", tmp);
			if (add_input_len_byte != 0) {
				for (unsigned int w = 0; w < add_input_len_byte; w++) {
					fscanf(req, "%02X", &RX);
					additional_input2[w] = RX;
					printf("%02X", additional_input2[w]);
					fprintf(rsp, "%02X", RX);
				}
			}


			fprintf(rsp, "\nReturnedBits = ");
			printf("\nReturnedBits = ");
			Instant_Fnc(&drbg_ctx, EntropyInput, entropy_input_len_byte, Nonce, nonce_len_byte, personal_string, personal_string_len_byte);
			reseed_fnc(&drbg_ctx, EntropyreseedInput, entropy_input_len_byte, additional_input_reseed, add_input_len_byte);
			generate_fnc(&drbg_ctx, EntropyreseedInput, entropy_input_len_byte, additional_input1, add_input_len_byte, output, outlen_byte);
			
			generate_fnc(&drbg_ctx, EntropyreseedInput, entropy_input_len_byte, additional_input2, add_input_len_byte, output, outlen_byte);
			for (unsigned int w = 0; w < outlen_byte; w++) {
				printf("%02X", output[w]);
				fprintf(rsp, "%02X", output[w]);
			}
			printf("\n");
			hash_drbg_ctx_free_no_p(&drbg_ctx);
		}
		free(EntropyInput);
		free(Nonce);
		free(personal_string);
		free(EntropyreseedInput);
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
#endif