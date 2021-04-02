#include "SHA512.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const ULONGLONG SHA512_K[80] =
{
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
	0x3956c25bf348b538, 0x59f111f1b605d019,0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
	0xd807aa98a3030242, 0x12835b0145706fbe , 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
	0xe49b69c19ef14ad2, 0xefbe4786384f25e3,0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5 ,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
	0xc6e00bf33da88fc2, 0xd5a79147930aa725,0x06ca6351e003826f, 0x142929670a0e6e70,
	0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
	0xa2bfe8a14cf10364, 0xa81a664bbc423001,0xc24b8b70d0f89791, 0xc76c51a30654be30,
	0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
	0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
	0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
	0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
	0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
	0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};


#if defined(_MSC_VER)

#define ROTL_ULONGLONG(x, n) _rotl64((x), (n))
#define ROTR_ULONGLONG(x, n) _rotr64((x), (n))  
#else
#define ROTL_ULONGLONG(x, n) ((ULONGLONG)((x) << (n)) | (ULONGLONG)((x) >> (64 - (n))))
#define ROTR_ULONGLONG(x, n) ((ULONGLONG)((x) >> (n)) | (ULONGLONG)((x) << (64 - (n))))
#endif

#define ENDIAN_REVERSE_ULONGLONG(dwS)	( (ROTL_ULONGLONG((dwS),  8) & 0x000000ff000000ff)\
									| (ROTL_ULONGLONG((dwS), 24) & 0x0000ff000000ff00)\
									| (ROTL_ULONGLONG((dwS), 40) & 0x00ff000000ff0000) \
									| (ROTL_ULONGLONG((dwS), 56) & 0xff000000ff000000)  )




#if defined(BIG_ENDIAN)
#define BIG_B2D(B, D)		D = *(ULONGLONG_PTR)(B)
#define BIG_D2B(D, B)		*(ULONGLONG_PTR)(B) = (ULONGLONG)(D)
#define LITTLE_B2D(B, D)	D = ENDIAN_REVERSE_ULONGLONG(*(ULONGLONG_PTR)(B))
#define LITTLE_D2B(D, B)	*(ULONGLONG_PTR)(B) = ENDIAN_REVERSE_ULONGLONG(D)
#elif defined(LITTLE_ENDIAN)
#define BIG_B2D(B, D)		D = ENDIAN_REVERSE_ULONGLONG(*(ULONGLONG_PTR)(B))
#define BIG_D2B(D, B)		*(ULONGLONG_PTR)(B) = ENDIAN_REVERSE_ULONGLONG(D)
#define LITTLE_B2D(B, D)	D = *(ULONGLONG_PTR)(B)
#define LITTLE_D2B(D, B)	*(ULONGLONG_PTR)(B) = (ULONGLONG)(D)
#else
#error ERROR : Invalid DataChangeType
#endif

#define RR(x, n)		ROTR_ULONGLONG(x, n)
#define SS(x, n)		(x >> n)

#define Ch(x, y, z)		((x & y) ^ ((~x) & z))
#define Maj(x, y, z)	((x & y) ^ (x & z) ^ (y & z))
#define Sigma0(x)		(RR(x,  28) ^ RR(x, 34) ^ RR(x, 39))
#define Sigma1(x)		(RR(x,  14) ^ RR(x, 18) ^ RR(x, 41))

#define RHO0(x)			(RR(x,  1) ^ RR(x, 8) ^ SS(x,  7))
#define RHO1(x)			(RR(x, 19) ^ RR(x, 61) ^ SS(x, 6))

void SHA512_Transform(ULONGLONG* Message, ULONGLONG* ChainVar)
{
	ULONGLONG a, b, c, d, e, f, g, h, T1, X[80];
	ULONGLONG j;

#define FF(a, b, c, d, e, f, g, h, j) {							\
	T1 = h + Sigma1(e) + Ch(e, f, g) + SHA512_K[j] + X[j];		\
	d += T1;													\
	h = T1 + Sigma0(a) + Maj(a, b, c);							\
}

#if defined(BIG_ENDIAN)
#define GetData(x)	x
#else
#define GetData(x)	ENDIAN_REVERSE_ULONGLONG(x)
#endif
	for (j = 0; j < 16; j++) {
		X[j] = GetData(Message[j]);
	}
	for (j = 16; j < 80; j++) {
		X[j] = RHO1(X[j - 2]) + X[j - 7] + RHO0(X[j - 15]) + X[j - 16];
	}


	a = ChainVar[0];
	b = ChainVar[1];
	c = ChainVar[2];
	d = ChainVar[3];
	e = ChainVar[4];
	f = ChainVar[5];
	g = ChainVar[6];
	h = ChainVar[7];
	
	for (j = 0; j < 80; j += 8)
	{
		FF(a, b, c, d, e, f, g, h, j + 0);
		FF(h, a, b, c, d, e, f, g, j + 1);
		FF(g, h, a, b, c, d, e, f, j + 2);
		FF(f, g, h, a, b, c, d, e, j + 3);
		FF(e, f, g, h, a, b, c, d, j + 4);
		FF(d, e, f, g, h, a, b, c, j + 5);
		FF(c, d, e, f, g, h, a, b, j + 6);
		FF(b, c, d, e, f, g, h, a, j + 7);
	}

	ChainVar[0] += a;
	ChainVar[1] += b;
	ChainVar[2] += c;
	ChainVar[3] += d;
	ChainVar[4] += e;
	ChainVar[5] += f;
	ChainVar[6] += g;
	ChainVar[7] += h;
}

void SHA512_Init(OUT SHA512_INFO* Info)
{
	Info->uChainVar[0] = 0x6a09e667f3bcc908;
	Info->uChainVar[1] = 0xbb67ae8584caa73b;
	Info->uChainVar[2] = 0x3c6ef372fe94f82b;
	Info->uChainVar[3] = 0xa54ff53a5f1d36f1;
	Info->uChainVar[4] = 0x510e527fade682d1;
	Info->uChainVar[5] = 0x9b05688c2b3e6c1f;
	Info->uChainVar[6] = 0x1f83d9abfb41bd6b;
	Info->uChainVar[7] = 0x5be0cd19137e2179;

	Info->uHighLength = Info->uLowLength = 0;
}

void SHA512_Process(OUT SHA512_INFO* Info, IN const BYTE* pszMessage, IN ULONGLONG uDataLen)
{
	ULONGLONG temp = 0;
	temp = Info->uLowLength + (uDataLen << 3);
	if (temp < Info->uLowLength) {
		Info->uHighLength += 1;
	}
	Info->uLowLength = temp;
	Info->uHighLength += (uDataLen >> 61);

	while (uDataLen >= SHA512_DIGEST_BLOCKLEN)
	{
		memcpy((ULONGLONG_PTR)Info->szBuffer, pszMessage, (SINT)SHA512_DIGEST_BLOCKLEN);
		SHA512_Transform((ULONGLONG_PTR)Info->szBuffer, Info->uChainVar);
		pszMessage += SHA512_DIGEST_BLOCKLEN;
		uDataLen -= SHA512_DIGEST_BLOCKLEN;
	}

	memcpy((UCHAR_PTR)Info->szBuffer, pszMessage, uDataLen);
}

void SHA512_Close(OUT SHA512_INFO* Info, IN BYTE* pszDigest)
{
	ULONGLONG Index;

	Index = (Info->uLowLength >> 3) % SHA512_DIGEST_BLOCKLEN;
	Info->szBuffer[Index++] = 0x80;

	if (Index > SHA512_DIGEST_BLOCKLEN - 16)
	{
		memset((UCHAR_PTR)Info->szBuffer + Index, 0, (SINT)(SHA512_DIGEST_BLOCKLEN - Index));
		SHA512_Transform((ULONGLONG_PTR)Info->szBuffer, Info->uChainVar);
		memset((UCHAR_PTR)Info->szBuffer, 0, (SINT)SHA512_DIGEST_BLOCKLEN - 16);
	}
	else
		memset((UCHAR_PTR)Info->szBuffer + Index, 0, (SINT)(SHA512_DIGEST_BLOCKLEN - Index - 16));

#if defined(LITTLE_ENDIAN)
	Info->uLowLength = ENDIAN_REVERSE_ULONGLONG(Info->uLowLength);
	Info->uHighLength = ENDIAN_REVERSE_ULONGLONG(Info->uHighLength);
#endif

	((ULONGLONG_PTR)Info->szBuffer)[SHA512_DIGEST_BLOCKLEN / 8 - 2] = Info->uHighLength;
	((ULONGLONG_PTR)Info->szBuffer)[SHA512_DIGEST_BLOCKLEN / 8 - 1] = Info->uLowLength;

	SHA512_Transform((ULONGLONG_PTR)Info->szBuffer, Info->uChainVar);

	for (int i = 0; i < SHA512_DIGEST_VALUELEN; i += 8) {
		BIG_D2B((Info->uChainVar)[i / 8], &(pszDigest[i]));
	}
}

void SHA512_Encrpyt(IN const BYTE* pszMessage, IN ULONGLONG uPlainTextLen, OUT BYTE* pszDigest)
{
	SHA512_INFO info;

	SHA512_Init(&info);

	SHA512_Process(&info, pszMessage, uPlainTextLen);

	SHA512_Close(&info, pszDigest);
}