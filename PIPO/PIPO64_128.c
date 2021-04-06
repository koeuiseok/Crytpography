#include <stdio.h>
#include <stdlib.h>

#define ROUND 13
#define SIZE 4				//64
#define INT_NUM 4			//64
#define MASTER_KEY_SIZE 2	//128


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u16 MASTER_KEY[MASTER_KEY_SIZE * INT_NUM] = { 0, };
u16 ROUND_KEY[(ROUND + 1) * INT_NUM] = { 0, };
u16 PLAIN_TEXT[SIZE] = { 0, };
u16 CIPHER_TEXT[SIZE] = { 0, };

void keyadd(u8* val, u8* rk)
{
	val[0] ^= rk[0];
	val[1] ^= rk[1];
	val[2] ^= rk[2];
	val[3] ^= rk[3];
	val[4] ^= rk[4];
	val[5] ^= rk[5];
	val[6] ^= rk[6];
	val[7] ^= rk[7];
}

void sbox(u8* X)
{
	u8 T[3] = { 0, };
	//(MSB: x[7], LSB: x[0]) 
	// Input: x[7], x[6], x[5], x[4], x[3], x[2], x[1], x[0] 
	//S5_1
	X[5] ^= (X[7] & X[6]);
	X[4] ^= (X[3] & X[5]);
	X[7] ^= X[4];
	X[6] ^= X[3];
	X[3] ^= (X[4] | X[5]);
	X[5] ^= X[7];
	X[4] ^= (X[5] & X[6]);
	//S3
	X[2] ^= X[1] & X[0];
	X[0] ^= X[2] | X[1];
	X[1] ^= X[2] | X[0];
	X[2] = ~X[2];
	// Extend XOR
	X[7] ^= X[1];	X[3] ^= X[2];	X[4] ^= X[0];
	//S5_2
	T[0] = X[7];	T[1] = X[3];	T[2] = X[4];
	X[6] ^= (T[0] & X[5]);
	T[0] ^= X[6];
	X[6] ^= (T[2] | T[1]);
	T[1] ^= X[5];
	X[5] ^= (X[6] | T[2]);
	T[2] ^= (T[1] & T[0]);
	// Truncate XOR and bit change
	X[2] ^= T[0];	T[0] = X[1] ^ T[2];	X[1] = X[0] ^ T[1];	X[0] = X[7];	X[7] = T[0];
	T[1] = X[3];	X[3] = X[6];	X[6] = T[1];
	T[2] = X[4];	X[4] = X[5];	X[5] = T[2];
	// Output: (MSb) x[7], x[6], x[5], x[4], x[3], x[2], x[1], x[0] (LSb)
}

void inv_sbox(u8* X)
{	//(MSB: x[7], LSB: x[0]) 
	// Input: x[7], x[6], x[5], x[4], x[3], x[2], x[1], x[0] 

	u8 T[3] = { 0, };

	T[0] = X[7]; X[7] = X[0]; X[0] = X[1]; X[1] = T[0];
	T[0] = X[7];	T[1] = X[6];	T[2] = X[5];
	// S52 inv
	X[4] ^= (X[3] | T[2]);
	X[3] ^= (T[2] | T[1]);
	T[1] ^= X[4];
	T[0] ^= X[3];
	T[2] ^= (T[1] & T[0]);
	X[3] ^= (X[4] & X[7]);
	//  Extended XOR
	X[0] ^= T[1]; X[1] ^= T[2]; X[2] ^= T[0];
	T[0] = X[3]; X[3] = X[6]; X[6] = T[0];
	T[0] = X[5]; X[5] = X[4]; X[4] = T[0];
	//  Truncated XOR
	X[7] ^= X[1];	X[3] ^= X[2];	X[4] ^= X[0];
	// Inv_S5_1
	X[4] ^= (X[5] & X[6]);
	X[5] ^= X[7];
	X[3] ^= (X[4] | X[5]);
	X[6] ^= X[3];
	X[7] ^= X[4];
	X[4] ^= (X[3] & X[5]);
	X[5] ^= (X[7] & X[6]);
	// Inv_S3
	X[2] = ~X[2];
	X[1] ^= X[2] | X[0];
	X[0] ^= X[2] | X[1];
	X[2] ^= X[1] & X[0];
	// Output: x[7], x[6], x[5], x[4], x[3], x[2], x[1], x[0]
}

//left rotation: (0,7,4,3,6,5,1,2)
void pbox(u8* X)
{
	X[1] = ((X[1] << 7)) | ((X[1] >> 1));
	X[2] = ((X[2] << 4)) | ((X[2] >> 4));
	X[3] = ((X[3] << 3)) | ((X[3] >> 5));
	X[4] = ((X[4] << 6)) | ((X[4] >> 2));
	X[5] = ((X[5] << 5)) | ((X[5] >> 3));
	X[6] = ((X[6] << 1)) | ((X[6] >> 7));
	X[7] = ((X[7] << 2)) | ((X[7] >> 6));

}

//left rotation(inverse): (0,1,4,5,2,3,7,6)
void inv_pbox(u8* X)
{
	X[1] = ((X[1] << 1)) | ((X[1] >> 7));
	X[2] = ((X[2] << 4)) | ((X[2] >> 4));
	X[3] = ((X[3] << 5)) | ((X[3] >> 3));
	X[4] = ((X[4] << 2)) | ((X[4] >> 6));
	X[5] = ((X[5] << 3)) | ((X[5] >> 5));
	X[6] = ((X[6] << 7)) | ((X[6] >> 1));
	X[7] = ((X[7] << 6)) | ((X[7] >> 2));
}

void ENC(u16* PLAIN_TEXT, u16* ROUND_KEY, u16* CIPHER_TEXT) {
	int i = 0;
	u8* P = (u8*)PLAIN_TEXT;
	u8* RK = (u8*)ROUND_KEY;

	for (int j = 0; j < 8; j++)
	{
		printf("%02X\t", P[j]);
	}

	printf("\n=====RK=====\n");
	for (int j = 0; j < 56; j++)
	{
		printf("%02X\t", RK[j]);
	}


	keyadd(P, RK);

	for (i = 1; i < ROUND + 1; i++)
	{
		sbox(P);
		pbox(P);
		keyadd(P, RK + (i * 8));

	}

	printf("\n\n==CIPHER_TEXT==\n");
	for (int j = 0; j < 8; j++)
	{
		printf("%02X\t", P[j]);
	}

}



void ROUND_KEY_GEN() {
	u32 i, j;
	u16 RCON = 0;

	printf("==PLAIN_TEXT==\n");

	//PIPO-64/128,PIPO-64/256 test vector
	PLAIN_TEXT[0] = 0x0026;
	PLAIN_TEXT[1] = 0x1E27;
	PLAIN_TEXT[2] = 0x52F6;
	PLAIN_TEXT[3] = 0x0985;

	for (i = SIZE; i > 0; i--)
		printf("0x%04X, \t", PLAIN_TEXT[i - 1]);

	printf("\n==MASTER_KEY==\n");

	//PIPO-64/128 test vector
	MASTER_KEY[0] = 0x2297;
	MASTER_KEY[2] = 0x20AD;
	MASTER_KEY[4] = 0x28D2;
	MASTER_KEY[6] = 0x16DD;
	MASTER_KEY[1] = 0x2E15;
	MASTER_KEY[3] = 0x7E1D;
	MASTER_KEY[5] = 0x7794;
	MASTER_KEY[7] = 0x6DC4;

	for (i = MASTER_KEY_SIZE; i > 0; i--) {
		for (j = INT_NUM; j > 0; j--) {
			printf("0x%04X, \t", MASTER_KEY[INT_NUM * (i - 1) + (j - 1)]);
		}
	}

	printf("\n==ROUND_KEY==\n");
	for (i = 0; i < ROUND + 1; i++) {
		for (j = 0; j < INT_NUM; j++)
			ROUND_KEY[INT_NUM * i + j] = MASTER_KEY[(INT_NUM * i + j) % (MASTER_KEY_SIZE * INT_NUM)];
		ROUND_KEY[INT_NUM * i] ^= RCON;
		RCON++;
		for (j = INT_NUM; j > 0; j--)
			printf("0x%04X, \t", ROUND_KEY[INT_NUM * i + (j - 1)]);

		printf("\n");
	}



}



void ko_PIPO()
{
	printf("\n\n==ko==\n\n");
	unsigned char newPlaintext[8] = { 0x26, 0x00, 0x27, 0x1E, 0xF6, 0x52, 0x85, 0x09 };
	unsigned char newMasterkey[16] = { 0x97, 0x22, 0x15, 0x2E, 0xAD, 0x20, 0x1D, 0x7E, 0xD2,0x28, 0x94, 0x77, 0xDD, 0x16, 0xC4, 0x6D };
	unsigned char koRK[112];
	printf("\n==ROUND_KEY==\n");
	unsigned char RCON = 0;
	for (int i = 0; i < ROUND + 1; i++) {
		for (int j = 0; j < 8; j++)
			koRK[8 * i + j] = newMasterkey[(8 * i + j) % (MASTER_KEY_SIZE * 8)];
		koRK[8 * i] ^= RCON;
		RCON++;
	}

	for (int j = 0; j < 56; j++)
	{
		printf("%02X\t", koRK[j]);
	}

	keyadd(newPlaintext, koRK);
	for (int i = 1; i < ROUND + 1; i++)
	{
		sbox(newPlaintext);
		pbox(newPlaintext);
		keyadd(newPlaintext, koRK + (i * 8));
	}

	printf("\n\n==CIPHER_TEXT==\n");
	for (int j = 0; j < 8; j++)
	{
		printf("%02X\t", newPlaintext[j]);
	}


}

int main(void) {

	ROUND_KEY_GEN();

	ENC(PLAIN_TEXT, ROUND_KEY, CIPHER_TEXT);

	printf("\n\n==CIPHER_TEXT==\n");
	printf("%04X, %04X, %04X, %04X\n", PLAIN_TEXT[3], PLAIN_TEXT[2], PLAIN_TEXT[1], PLAIN_TEXT[0]);

	ko_PIPO();

	return EXIT_SUCCESS;
}

