#include <stdio.h>
#include <stdlib.h>

#define ROUND 13
#define SIZE 4              //64 = 32 * 2
#define INT_NUM 4           //64 = 32 * 2
#define MASTER_KEY_SIZE 2   //128 = 64 * 2


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u16 MASTER_KEY[MASTER_KEY_SIZE * INT_NUM] = { 0, };
u16 ROUND_KEY[(ROUND + 1) * INT_NUM] = { 0, };
u16 PLAIN_TEXT[SIZE] = { 0, };
u16 CIPHER_TEXT[SIZE] = { 0, };

#define double_pt 1
#define one_pt 0

void asm_enc(u8* PLAIN_TEXT, u8* ROUND_KEY)
{

    asm(" mov.b 0x0(r12), r4\r\n");
    asm(" mov.b 0x1(r12), r5\r\n");
    asm(" mov.b 0x2(r12), r6\r\n");
    asm(" mov.b 0x3(r12), r7\r\n");
    asm(" mov.b 0x4(r12), r8\r\n");
    asm(" mov.b 0x5(r12), r9\r\n");
    asm(" mov.b 0x6(r12), r10\r\n"); //평문을 general register에 저장
    asm(" mov.b 0x7(r12), r11\r\n");  //평문 주솟값 : r12
    asm(" push r12\r\n");

    //round number
    asm(" mov.b #13, r12\r\n");

    // r4 : p[0] ~ r11 : p[7]

    //key add

        asm(" xor.b 0x0(r13), r4\r\n");
        asm(" xor.b 0x1(r13), r5\r\n");
        asm(" xor.b 0x2(r13), r6\r\n");
        asm(" xor.b 0x3(r13), r7\r\n");
        asm(" xor.b 0x4(r13), r8\r\n");
        asm(" xor.b 0x5(r13), r9\r\n");
        asm(" xor.b 0x6(r13), r10\r\n");
        asm(" xor.b 0x7(r13), r11\r\n");

//sbox:
// r4 : p[0], p[7] = r11
        //S5_1
    asm(" mov.b r11, r15\r\n");
    asm(" and.b r10, r15\r\n");
    asm(" xor.b r15, r9\r\n"); // X[5] ^= (X[7] & X[6]);

    asm(" mov.b r7, r15\r\n");
    asm(" and.b r9, r15\r\n");
    asm(" xor.b r15, r8\r\n"); // X[4] ^= (X[3] & X[5]);

    asm(" xor.b r8, r11\r\n"); // X[7] ^= X[4];

    asm(" xor.b r7, r10\r\n"); // X[6] ^= X[3];

    asm(" mov.b r9, r15\r\n");
    asm(" or.b r8, r15\r\n");
    asm(" xor.b r15, r7\r\n"); // X[3] ^= (X[4] | X[5]);

    asm(" xor.b r11, r9\r\n"); // X[5] ^= X[7];

    asm(" mov.b r9, r15\r\n");
    asm(" and.b r10, r15\r\n");
    asm(" xor.b r15, r8\r\n"); // X[4] ^= (X[5] & X[6]);



    //S3
    asm(" mov.b r5, r15\r\n");
    asm(" and.b r4, r15\r\n");
    asm(" xor.b r15, r6\r\n"); // X[2] ^= X[1] & X[0];

    asm(" mov.b r5, r15\r\n");
    asm(" or.b r6, r15\r\n");
    asm(" xor.b r15, r4\r\n"); // X[0] ^= X[2] | X[1];

    asm(" mov.b r6, r15\r\n");
    asm(" or.b r4, r15\r\n");
    asm(" xor.b r15, r5\r\n"); // X[1] ^= X[2] | X[0];

    asm(" xor.b #0xff, r6\r\n"); //X[2] = ~X[2];

    //X[7] ^= X[1];   X[3] ^= X[2];   X[4] ^= X[0];
    asm(" xor.b r5, r11\r\n");
    asm(" xor.b r6, r7\r\n");
    asm(" xor.b r4, r8\r\n");

    //good

    //S5_2
    asm(" push r13\r\n");
    //T[0] = X[7]; <= r12    T[1] = X[3]; <= r13    T[2] = X[4]; <= r14 안쓰는거  r14. 만든거 r13 tmp r15, r12:for문
    asm(" mov.b r11, r12\r\n");
    asm(" mov.b r7, r13\r\n");
    asm(" mov.b r8, r14\r\n");
//        X[6] ^= (T[0] & X[5]);
    asm(" mov.b r12, r15\r\n");
    asm(" and.b r9, r15\r\n");
    asm(" xor.b r15, r10\r\n");

    asm(" xor.b r10, r12\r\n");//        T[0] ^= X[6];

    // X[6] ^= (T[2] | T[1]);
    asm(" mov.b r13, r15\r\n");
    asm(" or.b r14, r15\r\n");
    asm(" xor.b r15, r10\r\n");

    asm(" xor.b r9, r13\r\n"); // T[1] ^= X[5];

//        X[5] ^= (X[6] | T[2]);
    asm(" mov.b r14, r15\r\n");
    asm(" or.b r10, r15\r\n");
    asm(" xor.b r15, r9\r\n");

//        T[2] ^= (T[1] & T[0]);
    asm(" mov.b r12, r15\r\n");
    asm(" and.b r13, r15\r\n");
    asm(" xor.b r15, r14\r\n");

    // Truncate XOR and bit change
    //X[2] ^= T[0];
    asm(" xor.b r12, r6\r\n");
    //T[0] = X[1] ^ T[2];
    asm(" mov.b r5, r12\r\n");
    asm(" xor.b r14, r12\r\n");

    //X[1] = X[0] ^ T[1];
    asm(" mov.b r4, r5\r\n");
    asm(" xor.b r13, r5\r\n");

    //X[0] = X[7];
    asm(" mov.b r11, r4\r\n");
    //X[7] = T[0];
    asm(" mov.b r12, r11\r\n");

    //T[1] = X[3];    X[3] = X[6];    X[6] = T[1];
    asm(" mov.b r7, r13\r\n");
    asm(" mov.b r10, r7\r\n");
    asm(" mov.b r13, r10\r\n");

    //T[2] = X[4];    X[4] = X[5];    X[5] = T[2];
    asm(" mov.b r8, r14\r\n");
    asm(" mov.b r9, r8\r\n");
    asm(" mov.b r14, r9\r\n");

    asm(" pop r13\r\n");

    // X[1] = ((X[1] << 7)) | ((X[1] >> 1));
    asm(" mov.b r5, r15\r\n");
    asm(" rra.b r15\r\n");
    asm(" rrc.b r5\r\n");

    // X[2] = ((X[2] << 4)) | ((X[2] >> 4));
    asm(" rla.b r6\r\n");
    asm(" adc.b r6\r\n");
    asm(" rla.b r6\r\n");
    asm(" adc.b r6\r\n");
    asm(" rla.b r6\r\n");
    asm(" adc.b r6\r\n");
    asm(" rla.b r6\r\n");
    asm(" adc.b r6\r\n");

    // X[3] = ((X[3] << 3)) | ((X[3] >> 5));
    asm(" rla.b r7\r\n");
    asm(" adc.b r7\r\n");
    asm(" rla.b r7\r\n");
    asm(" adc.b r7\r\n");
    asm(" rla.b r7\r\n");
    asm(" adc.b r7\r\n");

    // X[4] = ((X[4] << 6)) | ((X[4] >> 2));
    asm(" mov.b r8, r15\r\n");
    asm(" rra.b r15\r\n");
    asm(" rrc.b r8\r\n");
    asm(" rra.b r15\r\n");
    asm(" rrc.b r8\r\n");

    // X[5] = ((X[5] << 5)) | ((X[5] >> 3));
    asm(" mov.b r9, r15\r\n");
    asm(" rra.b r15\r\n");
    asm(" rrc.b r9\r\n");
    asm(" rra.b r15\r\n");
    asm(" rrc.b r9\r\n");
    asm(" rra.b r15\r\n");
    asm(" rrc.b r9\r\n");

    // X[6] = ((X[6] << 1)) | ((X[6] >> 7));
    asm(" rla.b r10\r\n");
    asm(" adc.b r10\r\n");

    // X[7] = ((X[7] << 2)) | ((X[7] >> 6));
    asm(" rla.b r11\r\n");
    asm(" adc.b r11\r\n");
    asm(" rla.b r11\r\n");
    asm(" adc.b r11\r\n");

// round is over



    asm(" pop r12\r\n");
}



void PIPO_setting()
{
    unsigned char newPlaintext[8] = { 0x26, 0x00, 0x27, 0x1E, 0xF6, 0x52, 0x85, 0x09 };
    unsigned char newMasterkey[16] = { 0x97, 0x22, 0x15, 0x2E, 0xAD, 0x20, 0x1D, 0x7E, 0xD2,0x28, 0x94, 0x77, 0xDD, 0x16, 0xC4, 0x6D };
    unsigned char RK[112];
    u16 double_RK[112];
    u16 double_PT[8];
    unsigned char RCON = 0;
    unsigned int i,j;
    for (i = 0; i < ROUND + 1; i++) {
        for (j = 0; j < 8; j++)
            RK[8 * i + j] = newMasterkey[(8 * i + j) % (MASTER_KEY_SIZE * 8)];
        RK[8 * i] ^= RCON;
        RCON++;
    }

    for(i=0; i<112; i++){
        double_RK[i] =  RK[i] + (RK[i] <<8);
    }
    for(i=0; i<8; i++){
        double_PT[i] =  newPlaintext[i] + ((u16)newPlaintext[i] <<8);
    }
    //asm_enc(newPlaintext, RK);
    two_asm_enc(double_PT, double_RK);
}



int main(void) {

    PIPO_setting();

    return 0;
}
