#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "AES.h"

const unsigned char SBox[256] = {
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };
const unsigned char InvSBox[256] = {
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
	0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
	0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
	0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
	0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
	0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
	0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
	0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
	0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
	0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
	0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
	0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
	0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
	0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
	0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
	0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };

void SubBytes(unsigned char* in_state) {
	for (int i = 0; i < 16; i++) {
		in_state[i] = SBox[in_state[i]];
	}
}

void InvSubBytes(unsigned char* in_state) {
	for (int i = 0; i < 16; i++) {
		in_state[i] = InvSBox[in_state[i]];
	}
}

unsigned char SB(unsigned char ar) {
	ar = SBox[ar];
	return ar;
}

void ShiftRows1(unsigned char* in_state) {
	unsigned char tmp[16] = { 0, };
	for (int i = 0; i < 4; i++) {
		tmp[4 * i] = in_state[4 * i];
		tmp[4 * i+1] = in_state[(4 * i+5)%16];
		tmp[4 * i + 2] = in_state[(4 * i + 10) % 16];
		tmp[4 * i + 3] = in_state[(4 * i + 15) % 16];
	}
	for (int j = 0; j < 16; j++) {
		in_state[j] = tmp[j];
	}
}

void ShiftRows(unsigned char* in_state) {
	unsigned char tmp = 0;
	tmp = in_state[1];
	in_state[1] = in_state[5];
	in_state[5] = in_state[9];
	in_state[9] = in_state[13];
	in_state[13] = tmp;

	tmp = in_state[2];
	in_state[2] = in_state[10];
	in_state[10] = tmp;
	tmp = in_state[6];
	in_state[6] = in_state[14];
	in_state[14] = tmp;

	tmp = in_state[15];
	in_state[15] = in_state[11];
	in_state[11] = in_state[7];
	in_state[7] = in_state[3];
	in_state[3] = tmp;
	return;
}

void InvShiftRows(unsigned char* in_state) {
	unsigned char tmp = 0;
	tmp = in_state[1];
	in_state[1] = in_state[13];
	in_state[13] = in_state[9];
	in_state[9] = in_state[5];
	in_state[5] = tmp;

	tmp = in_state[2];
	in_state[2] = in_state[10];
	in_state[10] = tmp;
	tmp = in_state[6];
	in_state[6] = in_state[14];
	in_state[14] = tmp;

	tmp = in_state[3];
	in_state[3] = in_state[7];
	in_state[7] = in_state[9];
	in_state[9] = in_state[15];
	in_state[15] = tmp;
	return;
}


unsigned char GM2(unsigned char p) {
	return xtimes(p);
}

unsigned char GM3(unsigned char p) {
	return p ^ GM2(p);
}

unsigned char GaloisMult1(unsigned char a, int b) {
	unsigned char x=0;
	unsigned char LSP;
	for (int i = 0; i < 4; i++) {
		if ((b & 1) == 1) x ^= a;
		LSP = a & 0x80;
		a = (a << 1) % 256;
		if (LSP == 0x80) a ^= 0x1b;
		b >>= 1;
	}
	return x % 256;
}


unsigned char GaloisMult(unsigned char a, int b) {
	unsigned char x;
	x = (a << 1) ^ ((a >> 7) * 0x1b);
	if (b == 2) return x % 256;
	else if (b == 3) return (x ^ a) % 256;
}

void xtimes_MixColumns(unsigned char* in_state) {
	unsigned char tmp[4] = { 0, };
	unsigned char column, imsi;
	for (int i = 0; i < 4; i++) {
		column = in_state[4 * i] ^ in_state[4 * i + 1]
			^ in_state[4 * i + 2] ^ in_state[4 * i + 3];
		imsi = in_state[4 * i] ^ in_state[4 * i + 1];
		imsi = xtimes(imsi); tmp[0]=imsi^ column ^ in_state[4 * i ];

		imsi = in_state[4 * i+1] ^ in_state[4 * i + 2];
		imsi = xtimes(imsi); tmp[1] = imsi ^ column ^ in_state[4 * i+1];

		imsi = in_state[4 * i+2] ^ in_state[4 * i + 3];
		imsi = xtimes(imsi); tmp[2] = imsi ^ column ^ in_state[4 * i+2];

		imsi = in_state[4 * i+3] ^ in_state[4 * i ];
		imsi = xtimes(imsi); tmp[3] = imsi ^ column ^ in_state[4 * i+3];

		in_state[4 * i] = tmp[0];
		in_state[4 * i + 1] = tmp[1];
		in_state[4 * i + 2] = tmp[2];
		in_state[4 * i + 3] = tmp[3];
	}
}

void Shift_Mix(unsigned char* in_state) {
	unsigned char tmp[16] = { 0, };
	unsigned char column, imsi;
	
	column = in_state[0] ^ in_state[5]
		^ in_state[10] ^ in_state[15];
	imsi = in_state[0] ^ in_state[5];
	imsi = xtimes(imsi); tmp[0] = imsi ^ column ^ in_state[0];

	imsi = in_state[5] ^ in_state[10];
	imsi = xtimes(imsi); tmp[1] = imsi ^ column ^ in_state[5];

	imsi = in_state[10] ^ in_state[15];
	imsi = xtimes(imsi); tmp[2] = imsi ^ column ^ in_state[10];

	imsi = in_state[15] ^ in_state[0];
	imsi = xtimes(imsi); tmp[3] = imsi ^ column ^ in_state[15];

	column = in_state[4] ^ in_state[9]
		^ in_state[14] ^ in_state[3];
	imsi = in_state[4] ^ in_state[9];
	imsi = xtimes(imsi); tmp[4] = imsi ^ column ^ in_state[4];

	imsi = in_state[9] ^ in_state[14];
	imsi = xtimes(imsi); tmp[5] = imsi ^ column ^ in_state[9];

	imsi = in_state[14] ^ in_state[3];
	imsi = xtimes(imsi); tmp[6] = imsi ^ column ^ in_state[14];

	imsi = in_state[3] ^ in_state[4];
	imsi = xtimes(imsi); tmp[7] = imsi ^ column ^ in_state[3];

	column = in_state[8] ^ in_state[13]
		^ in_state[2] ^ in_state[7];
	imsi = in_state[8] ^ in_state[13];
	imsi = xtimes(imsi); tmp[8] = imsi ^ column ^ in_state[8];

	imsi = in_state[13] ^ in_state[2];
	imsi = xtimes(imsi); tmp[9] = imsi ^ column ^ in_state[13];

	imsi = in_state[2] ^ in_state[7];
	imsi = xtimes(imsi); tmp[10] = imsi ^ column ^ in_state[2];

	imsi = in_state[7] ^ in_state[8];
	imsi = xtimes(imsi); tmp[11] = imsi ^ column ^ in_state[7];
	
	column = in_state[12] ^ in_state[1]
		^ in_state[6] ^ in_state[11];
	imsi = in_state[12] ^ in_state[1];
	imsi = xtimes(imsi); tmp[12] = imsi ^ column ^ in_state[12];

	imsi = in_state[1] ^ in_state[6];
	imsi = xtimes(imsi); tmp[13] = imsi ^ column ^ in_state[1];

	imsi = in_state[6] ^ in_state[11];
	imsi = xtimes(imsi); tmp[14] = imsi ^ column ^ in_state[6];

	imsi = in_state[11] ^ in_state[12];
	imsi = xtimes(imsi); tmp[15] = imsi ^ column ^ in_state[11];
}



void MixColumns(unsigned char* in_state) {
	unsigned char tmp[4] = { 0, };

	for (int i = 0; i < 4; i++) {
		tmp[0] = GaloisMult(in_state[4 * i],2) ^ GaloisMult(in_state[4 * i + 1],3) 
			^ in_state[4 * i + 2]^ in_state[4 * i + 3];
		tmp[1] = in_state[4 * i] ^ GaloisMult(in_state[4 * i + 1], 2) 
			^ GaloisMult(in_state[4 * i + 2], 3) ^ in_state[4 * i + 3];
		tmp[2] = in_state[4 * i] ^ in_state[4 * i + 1] 
			^ GaloisMult(in_state[4 * i + 2], 2) ^ GaloisMult(in_state[4 * i + 3], 3);
		tmp[3] = GaloisMult(in_state[4 * i], 3) ^ in_state[4 * i + 1] 
			^ in_state[4 * i + 2] ^ GaloisMult(in_state[4 * i + 3], 2);
		in_state[4 * i] = tmp[0];
		in_state[4 * i + 1] = tmp[1];
		in_state[4 * i + 2] = tmp[2];
		in_state[4 * i + 3] = tmp[3];
	}
}


void KeyExpansion(unsigned char* roundkey, int RN) {
	const unsigned char RCons[10] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36 };
	unsigned char tmp[4];
	tmp[0] = SB(roundkey[13]) ^ RCons[RN - 1];
	tmp[1] = SB(roundkey[14]);
	tmp[2] = SB(roundkey[15]);
	tmp[3] = SB(roundkey[12]);
	for (int i = 0; i < 4; i++) {
		roundkey[i] ^= tmp[i];
		roundkey[i + 4] ^= roundkey[i];
		roundkey[i + 8] ^= roundkey[i + 4];
		roundkey[i + 12] ^= roundkey[i + 8];
	}
}

void KeyExpansion_pre(unsigned char* pre_key, unsigned char* roundkey, int RN) {
	const unsigned char RCons[10] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36 };
	unsigned char tmp[4];
	tmp[0] = SB(pre_key[13]) ^ RCons[RN - 1];
	tmp[1] = SB(pre_key[14]);
	tmp[2] = SB(pre_key[15]);
	tmp[3] = SB(pre_key[12]);
	for (int i = 0; i < 4; i++) {
		roundkey[i] =pre_key[i]^ tmp[i];
		roundkey[i + 4] = roundkey[i]^pre_key[i+4];
		roundkey[i + 8] = roundkey[i + 4]^ pre_key[i + 8];
		roundkey[i + 12] = roundkey[i + 8]^ pre_key[i + 12];
	}
}


void AddRound(unsigned char* in_state, unsigned char* roundkey) {
	for (int i = 0; i < 16; i++) {
		in_state[i] ^= roundkey[i];
	}
}

void SSM(unsigned char* in_state) {
	unsigned char tmp[16] = { 0, };

	tmp[0] = GaloisMult(SBox[in_state[0]], 2) ^ GaloisMult(SBox[in_state[5]], 3)
		^ SBox[in_state[10]] ^ SBox[in_state[15]];
	tmp[1] = SBox[in_state[0]] ^ GaloisMult(SBox[in_state[5]], 2)
		^ GaloisMult(SBox[in_state[10]], 3) ^ SBox[in_state[15]];
	tmp[2] = SBox[in_state[0]] ^ SBox[in_state[5]]
		^ GaloisMult(SBox[in_state[10]], 2) ^ GaloisMult(SBox[in_state[15]], 3);
	tmp[3] = GaloisMult(SBox[in_state[0]], 3) ^ SBox[in_state[5]]
		^ SBox[in_state[10]] ^ GaloisMult(SBox[in_state[15]], 2);

	tmp[4] = GaloisMult(SBox[in_state[4]], 2) ^ GaloisMult(SBox[in_state[9]], 3)
		^ SBox[in_state[14]] ^ SBox[in_state[3]];
	tmp[5] = SBox[in_state[4]] ^ GaloisMult(SBox[in_state[9]], 2)
		^ GaloisMult(SBox[in_state[14]], 3) ^ SBox[in_state[3]];
	tmp[6] = SBox[in_state[4]] ^ SBox[in_state[9]]
		^ GaloisMult(SBox[in_state[14]], 2) ^ GaloisMult(SBox[in_state[3]], 3);
	tmp[7] = GaloisMult(SBox[in_state[4]], 3) ^ SBox[in_state[9]]
		^ SBox[in_state[14]] ^ GaloisMult(SBox[in_state[3]], 2);

	tmp[8] = GaloisMult(SBox[in_state[8]], 2) ^ GaloisMult(SBox[in_state[13]], 3)
		^ SBox[in_state[2]] ^ SBox[in_state[7]];
	tmp[9] = SBox[in_state[8]] ^ GaloisMult(SBox[in_state[13]], 2)
		^ GaloisMult(SBox[in_state[2]], 3) ^ SBox[in_state[7]];
	tmp[10] = SBox[in_state[8]] ^ SBox[in_state[13]]
		^ GaloisMult(SBox[in_state[2]], 2) ^ GaloisMult(SBox[in_state[7]], 3);
	tmp[11] = GaloisMult(SBox[in_state[8]], 3) ^ SBox[in_state[13]]
		^ SBox[in_state[2]] ^ GaloisMult(SBox[in_state[7]], 2);

	tmp[12] = GaloisMult(SBox[in_state[12]], 2) ^ GaloisMult(SBox[in_state[1]], 3)
		^ SBox[in_state[6]] ^ SBox[in_state[11]];
	tmp[13] = SBox[in_state[12]] ^ GaloisMult(SBox[in_state[1]], 2)
		^ GaloisMult(SBox[in_state[6]], 3) ^ SBox[in_state[11]];
	tmp[14] = SBox[in_state[12]] ^ SBox[in_state[1]]
		^ GaloisMult(SBox[in_state[6]], 2) ^ GaloisMult(SBox[in_state[11]], 3);
	tmp[15] = GaloisMult(SBox[in_state[12]], 3) ^ SBox[in_state[1]]
		^ SBox[in_state[6]] ^ GaloisMult(SBox[in_state[11]], 2);

	for (int j = 0; j < 16; j++) {
		in_state[j] = tmp[j];
	}
}


void AES_Enc(unsigned char* text, const unsigned char* key) {

	AddRound(text, key);
	for (int round = 1; round < Nr; round++) {
		SubBytes(text);
		ShiftRows(text);
		xtimes_MixColumns(text);
		KeyExpansion(key, round);
		AddRound(text, key);

	}
	SubBytes(text);
	ShiftRows(text);
	KeyExpansion(key, 10);
	AddRound(text, key);
}

void AES_Enc2(const unsigned char* text, unsigned char* outtext,const unsigned char* key) {
	for (int i = 0; i < 16; i++) {
		outtext[i] = text[i];
	}
	AddRound(outtext, key);
	for (int round = 1; round < Nr; round++) {
		SubBytes(outtext);
		ShiftRows(outtext);
		MixColumns(outtext);
		KeyExpansion(key, round);
		AddRound(outtext, key);

	}
	SubBytes(outtext);
	ShiftRows(outtext);
	KeyExpansion(key, 10);
	AddRound(outtext, key);
}

unsigned char GM9(unsigned char x) {
	return GM2(GM2(GM2(x)))+x;
}

unsigned char GM11(unsigned char x) {
	return GM2(GM2(GM2(x))+x) + x;
}

unsigned char GM13(unsigned char x) {
	return GM2(GM2(GM2(x)+x)) + x;
}

unsigned char GM14(unsigned char x) {
	return GM2(GM2(GM2(x) + x)+x);
}

void InvMixColumns(unsigned char* in_state) {
	unsigned char tmp[4] = { 0, };

	for (int i = 0; i < 4; i++) {
		tmp[0] = GM14(in_state[4 * i]) ^ GM11(in_state[4 * i + 1]) ^ GM13(in_state[4 * i + 2]) ^ GM9(in_state[4 * i + 3]);
		tmp[1] = GM9(in_state[4 * i]) ^ GM14(in_state[4 * i + 1]) ^ GM11(in_state[4 * i + 2]) ^ GM13(in_state[4 * i + 3]);
		tmp[2] = GM13(in_state[4 * i]) ^ GM9(in_state[4 * i + 1]) ^ GM14(in_state[4 * i + 2]) ^ GM11(in_state[4 * i + 3]);
		tmp[3] = GM11(in_state[4 * i]) ^ GM13(in_state[4 * i + 1]) ^ GM9(in_state[4 * i + 2]) ^ GM14(in_state[4 * i + 3]);
		in_state[4 * i] = tmp[0];
		in_state[4 * i + 1] = tmp[1];
		in_state[4 * i + 2] = tmp[2];
		in_state[4 * i + 3] = tmp[3];
	}
}

void AES_Dec(unsigned char* text ,unsigned char* key) {
	unsigned char* Roundkey[Nr + 1][16];
	for (int i = 0; i < 16; i++) {
		Roundkey[0][i] = key[i];
	}
	for (int round = 1; round <= Nr; round++) {
		KeyExpansion(Roundkey[round - 1], Roundkey[round], round);
	}

	AddRound(text, key);
	InvShiftRows(text);
	InvSubBytes(text);
	for (int round = 1; round < Nr; round++) {
		InvMixColumns(text);
		AddRound(text, Roundkey[round]);
		InvShiftRows(text);
		InvSubBytes(text);
	}
	AddRound(text, Roundkey[0]);
}
