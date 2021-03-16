#include<stdio.h>
#define Nr 10
void SubBytes(unsigned char* in_state);
unsigned char SB(unsigned char ar);
void ShiftRows(unsigned char* in_state);
unsigned char xtimes(unsigned char p);
unsigned char GM2(unsigned char p);
unsigned char GM3(unsigned char p);
void MixColumns(unsigned char* in_state);
void KeyExpansion(unsigned char* roundkey, int RN);
void AddRound(unsigned char* in_state, unsigned char* roundkey);
void Shift_Mix(unsigned char* in_state);
void AES_Enc(unsigned char* plaintext, const unsigned char* key);

void InvSubBytes(unsigned char* in_state);
void InvShiftRows(unsigned char* in_state);
void KeyExpansion_pre(unsigned char* pre_key, unsigned char* roundkey, int RN);
unsigned char GM9(unsigned char x);
unsigned char GM11(unsigned char x);
unsigned char GM13(unsigned char x);
unsigned char GM14(unsigned char x);
void InvMixColumns(unsigned char* in_state);
void AES_Dec(unsigned char* text, unsigned char* key);

void CTR_plus(unsigned char* CTR, int num);
void xor_CTR(unsigned char* CTR, unsigned char* text);
void AES_CTR(unsigned char* plaintext, unsigned char* ciphertext, unsigned char* key, unsigned char* CTR, int size);
void AES_CBC(unsigned char* plaintext, unsigned char* ciphertext, unsigned char* key, unsigned char* IV, int size);
void xor_IV(unsigned char* text, unsigned char* CB);
void AES_ECB(unsigned char* plaintext, unsigned char* ciphertext, unsigned char* key, int size);

unsigned char GaloisMult(unsigned char a, int b);
void galois_MixColumns(unsigned char* in_state);
void xtimes_MixColumns(unsigned char* in_state);
void practice_AES_Enc(unsigned char* text, const unsigned char* key);

#define xtimes(x) (x << 1) ^ ((x >> 7)*0x1b)
