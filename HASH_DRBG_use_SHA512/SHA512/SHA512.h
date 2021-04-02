#ifndef SHA512_H
#define SHA512_H  //ifndef ~, def~ 헤더 파일이 정의 안되어있다면 재정의

#ifdef  __cplusplus
extern "C" {
#endif

#ifndef OUT
#define OUT
#endif

#ifndef IN
#define IN
#endif

#ifndef INOUT
#define INOUT
#endif

#undef BIG_ENDIAN        //undef 정의 해제
#undef LITTLE_ENDIAN

#if defined(USER_BIG_ENDIAN)
#define BIG_ENDIAN
#elif defined(USER_LITTLE_ENDIAN)
#define LITTLE_ENDIAN
#else
#if 0
#define BIG_ENDIAN
#elif defined(_MSC_VER)
#define LITTLE_ENDIAN
#else
#error
#endif
#endif

	typedef unsigned long ULONG;
	typedef ULONG* ULONG_PTR;

	typedef unsigned long long ULONGLONG;
	typedef ULONGLONG* ULONGLONG_PTR;

	typedef unsigned int UINT;
	typedef UINT* UINT_PTR;

	typedef signed int SINT;
	typedef SINT* SINT_PTR;

	typedef unsigned char UCHAR;
	typedef UCHAR* UCHAR_PTR;

	typedef unsigned char BYTE;

#define SHA512_DIGEST_BLOCKLEN	128
#define SHA512_DIGEST_VALUELEN	64

	typedef struct {
		ULONGLONG uChainVar[SHA512_DIGEST_VALUELEN / 8];
		ULONGLONG uHighLength;
		ULONGLONG uLowLength;
		BYTE szBuffer[SHA512_DIGEST_BLOCKLEN];
	} SHA512_INFO;

	void SHA512_Init(OUT SHA512_INFO* Info);

	void SHA512_Process(OUT SHA512_INFO* Info, IN const BYTE* pszMessage, IN ULONGLONG uDataLen);

	void SHA512_Close(OUT SHA512_INFO* Info, IN BYTE* pszDigest);

	void SHA512_Encrpyt(IN const BYTE* pszMessage, IN ULONGLONG uPlainTextLen, OUT BYTE* pszDigest);


#ifdef  __cplusplus
}
#endif

#endif