//
//static unsigned char HIGHT_F0[256] = {
//        0x00,0x86,0x0D,0x8B,0x1A,0x9C,0x17,0x91,
//        0x34,0xB2,0x39,0xBF,0x2E,0xA8,0x23,0xA5,
//        0x68,0xEE,0x65,0xE3,0x72,0xF4,0x7F,0xF9,
//        0x5C,0xDA,0x51,0xD7,0x46,0xC0,0x4B,0xCD,
//        0xD0,0x56,0xDD,0x5B,0xCA,0x4C,0xC7,0x41,
//        0xE4,0x62,0xE9,0x6F,0xFE,0x78,0xF3,0x75,
//        0xB8,0x3E,0xB5,0x33,0xA2,0x24,0xAF,0x29,
//        0x8C,0x0A,0x81,0x07,0x96,0x10,0x9B,0x1D,
//        0xA1,0x27,0xAC,0x2A,0xBB,0x3D,0xB6,0x30,
//        0x95,0x13,0x98,0x1E,0x8F,0x09,0x82,0x04,
//        0xC9,0x4F,0xC4,0x42,0xD3,0x55,0xDE,0x58,
//        0xFD,0x7B,0xF0,0x76,0xE7,0x61,0xEA,0x6C,
//        0x71,0xF7,0x7C,0xFA,0x6B,0xED,0x66,0xE0,
//        0x45,0xC3,0x48,0xCE,0x5F,0xD9,0x52,0xD4,
//        0x19,0x9F,0x14,0x92,0x03,0x85,0x0E,0x88,
//        0x2D,0xAB,0x20,0xA6,0x37,0xB1,0x3A,0xBC,
//        0x43,0xC5,0x4E,0xC8,0x59,0xDF,0x54,0xD2,
//        0x77,0xF1,0x7A,0xFC,0x6D,0xEB,0x60,0xE6,
//        0x2B,0xAD,0x26,0xA0,0x31,0xB7,0x3C,0xBA,
//        0x1F,0x99,0x12,0x94,0x05,0x83,0x08,0x8E,
//        0x93,0x15,0x9E,0x18,0x89,0x0F,0x84,0x02,
//        0xA7,0x21,0xAA,0x2C,0xBD,0x3B,0xB0,0x36,
//        0xFB,0x7D,0xF6,0x70,0xE1,0x67,0xEC,0x6A,
//        0xCF,0x49,0xC2,0x44,0xD5,0x53,0xD8,0x5E,
//        0xE2,0x64,0xEF,0x69,0xF8,0x7E,0xF5,0x73,
//        0xD6,0x50,0xDB,0x5D,0xCC,0x4A,0xC1,0x47,
//        0x8A,0x0C,0x87,0x01,0x90,0x16,0x9D,0x1B,
//        0xBE,0x38,0xB3,0x35,0xA4,0x22,0xA9,0x2F,
//        0x32,0xB4,0x3F,0xB9,0x28,0xAE,0x25,0xA3,
//        0x06,0x80,0x0B,0x8D,0x1C,0x9A,0x11,0x97,
//        0x5A,0xDC,0x57,0xD1,0x40,0xC6,0x4D,0xCB,
//        0x6E,0xE8,0x63,0xE5,0x74,0xF2,0x79,0xFF };
//
//static unsigned char HIGHT_F1[256] = {
//        0x00,0x58,0xB0,0xE8,0x61,0x39,0xD1,0x89,
//        0xC2,0x9A,0x72,0x2A,0xA3,0xFB,0x13,0x4B,
//        0x85,0xDD,0x35,0x6D,0xE4,0xBC,0x54,0x0C,
//        0x47,0x1F,0xF7,0xAF,0x26,0x7E,0x96,0xCE,
//        0x0B,0x53,0xBB,0xE3,0x6A,0x32,0xDA,0x82,
//        0xC9,0x91,0x79,0x21,0xA8,0xF0,0x18,0x40,
//        0x8E,0xD6,0x3E,0x66,0xEF,0xB7,0x5F,0x07,
//        0x4C,0x14,0xFC,0xA4,0x2D,0x75,0x9D,0xC5,
//        0x16,0x4E,0xA6,0xFE,0x77,0x2F,0xC7,0x9F,
//        0xD4,0x8C,0x64,0x3C,0xB5,0xED,0x05,0x5D,
//        0x93,0xCB,0x23,0x7B,0xF2,0xAA,0x42,0x1A,
//        0x51,0x09,0xE1,0xB9,0x30,0x68,0x80,0xD8,
//        0x1D,0x45,0xAD,0xF5,0x7C,0x24,0xCC,0x94,
//        0xDF,0x87,0x6F,0x37,0xBE,0xE6,0x0E,0x56,
//        0x98,0xC0,0x28,0x70,0xF9,0xA1,0x49,0x11,
//        0x5A,0x02,0xEA,0xB2,0x3B,0x63,0x8B,0xD3,
//        0x2C,0x74,0x9C,0xC4,0x4D,0x15,0xFD,0xA5,
//        0xEE,0xB6,0x5E,0x06,0x8F,0xD7,0x3F,0x67,
//        0xA9,0xF1,0x19,0x41,0xC8,0x90,0x78,0x20,
//        0x6B,0x33,0xDB,0x83,0x0A,0x52,0xBA,0xE2,
//        0x27,0x7F,0x97,0xCF,0x46,0x1E,0xF6,0xAE,
//        0xE5,0xBD,0x55,0x0D,0x84,0xDC,0x34,0x6C,
//        0xA2,0xFA,0x12,0x4A,0xC3,0x9B,0x73,0x2B,
//        0x60,0x38,0xD0,0x88,0x01,0x59,0xB1,0xE9,
//        0x3A,0x62,0x8A,0xD2,0x5B,0x03,0xEB,0xB3,
//        0xF8,0xA0,0x48,0x10,0x99,0xC1,0x29,0x71,
//        0xBF,0xE7,0x0F,0x57,0xDE,0x86,0x6E,0x36,
//        0x7D,0x25,0xCD,0x95,0x1C,0x44,0xAC,0xF4,
//        0x31,0x69,0x81,0xD9,0x50,0x08,0xE0,0xB8,
//        0xF3,0xAB,0x43,0x1B,0x92,0xCA,0x22,0x7A,
//        0xB4,0xEC,0x04,0x5C,0xD5,0x8D,0x65,0x3D,
//        0x76,0x2E,0xC6,0x9E,0x17,0x4F,0xA7,0xFF };
//
//static unsigned char Delta[128] = {
//        0x5A,0x6D,0x36,0x1B,0x0D,0x06,0x03,0x41,
//        0x60,0x30,0x18,0x4C,0x66,0x33,0x59,0x2C,
//        0x56,0x2B,0x15,0x4A,0x65,0x72,0x39,0x1C,
//        0x4E,0x67,0x73,0x79,0x3C,0x5E,0x6F,0x37,
//        0x5B,0x2D,0x16,0x0B,0x05,0x42,0x21,0x50,
//        0x28,0x54,0x2A,0x55,0x6A,0x75,0x7A,0x7D,
//        0x3E,0x5F,0x2F,0x17,0x4B,0x25,0x52,0x29,
//        0x14,0x0A,0x45,0x62,0x31,0x58,0x6C,0x76,
//        0x3B,0x1D,0x0E,0x47,0x63,0x71,0x78,0x7C,
//        0x7E,0x7F,0x3F,0x1F,0x0F,0x07,0x43,0x61,
//        0x70,0x38,0x5C,0x6E,0x77,0x7B,0x3D,0x1E,
//        0x4F,0x27,0x53,0x69,0x34,0x1A,0x4D,0x26,
//        0x13,0x49,0x24,0x12,0x09,0x04,0x02,0x01,
//        0x40,0x20,0x10,0x08,0x44,0x22,0x11,0x48,
//        0x64,0x32,0x19,0x0C,0x46,0x23,0x51,0x68,
//        0x74,0x3A,0x5D,0x2E,0x57,0x6B,0x35,0x5A };
//
//
//void HIGHT_keygen(unsigned char* MK, unsigned char* RK)
//{
//    int i, j = 0;
//    for (i = 0; i < 4; i++) {
//        RK[i] = MK[i + 12];
//        RK[i+4] = MK[i];
//    }  //???? ??(0~3) ????????(4~7) => ???????? ?? 
//
//    for (i = 0; i < 8; i++) {
//        for (j = 0; j < 8; j++)
//            RK[8 + 16 * i + j] = MK[(j - i) & 7] + Delta[16 * i + j];
//        for (j = 0; j < 8; j++)
//            RK[16 + 16 * i + j] = MK[((j - i) & 7)+8] + Delta[16 * i + j+8];
//    } // ???????? ?? ???? ????(8~) SK?? ???????? ??????
//}
//
//
//
//void asm_hight_enc(unsigned char* text, unsigned char* use_key )
//{
//  // ???? ????(wk?? ????)
//  
//  asm("mov.b 0x1(r12), r5\n\t"  
//  "mov.b 0x3(r12), r7\n\t"
//  "mov.b 0x5(r12), r9\n\t"
//  " mov.b 0x7(r12), r11\n\t"  //x=p i=1,3,5,7
//  
//  );
//  
//  asm("mov.b 0x0(r12), r4\n\t  ");
//  asm("add.b 0x0(r13),r4\n\t");
//  
//  asm("mov.b 0x2(r12), r6\n\t");
//  asm("xor.b 0x1(r13),r6\n\t");
//  
//  asm("mov.b    0x4(r12),        r8\n\t");
//  asm("add.b    0x2(r13),       r8\n\t");
//  
//  asm("mov.b    0x6(r12),      r10\n\t");
//  asm("xor.b    0x3(r13),       r10\n\t");  // x= p+w or p^w
//  
//  asm("push.w r12\n\t");
//  //push  r12
//  
/////////////////////////////////////////////////////////////////////////////////////////////  
////  #define HIGHT_1R_ENC(k,i0,i1,i2,i3,i4,i5,i6,i7){      \
////  
////        X[i0] = (X[i0]^(HIGHT_F0[X[i1]]+RK[4*k+3]));  \
////  
////        X[i2] = (X[i2]+(HIGHT_F1[X[i3]]^RK[4*k+2]));  \
////
////        X[i4] = (X[i4]^(HIGHT_F0[X[i5]]+RK[4*k+1]));  \
////
////        X[i6] = (X[i6]+(HIGHT_F1[X[i7]]^RK[4*k]));    \
////
////    }
//////////////////////////////////////////////////////////////////////////////////////////////
//  
////1round ???? : r11 = i0,,,r4 = i7, ?????? sk0~3 <==>  0x8(13)~0xb(r13)
//  asm(  "mov.b  r10,    r15\n\t"  ); 
//  asm("mov.b    r10, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r11\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r6,    r15\n\t"  ); 
//  asm(  "mov.b  r6,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r7\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r8, r15\n\t"  );
//   asm(  "mov.b r8, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r9\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r4, r15\n\t"  ); 
//   asm(  "mov.b r4, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r5\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 1?????? ????????
//
//  
//  
//    
//  asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
////2round ????
//  asm(  "mov.b  r9,    r15\n\t"  ); 
//  asm("mov.b    r9, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r10\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r5,    r15\n\t"  ); 
//  asm(  "mov.b  r5,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r6\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r7, r15\n\t"  );
//   asm(  "mov.b r7, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r8\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r11, r15\n\t"  ); 
//   asm(  "mov.b r11, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r4\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 2?????? ????????  
//
//  
//  
//  
//  
// asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
////3round ????
//  asm(  "mov.b  r8,    r15\n\t"  ); 
//  asm("mov.b    r8, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r9\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r4,    r15\n\t"  ); 
//  asm(  "mov.b  r4,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r5\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r6, r15\n\t"  );
//   asm(  "mov.b r6, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r7\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r10, r15\n\t"  ); 
//   asm(  "mov.b r10, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r11\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 3?????? ????????  
//
//  
//  
//  
//  
//   asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////4round ????
//  asm(  "mov.b  r7,    r15\n\t"  ); 
//  asm("mov.b    r7, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r8\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r11,    r15\n\t"  ); 
//  asm(  "mov.b  r11,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r4\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r5, r15\n\t"  );
//   asm(  "mov.b r5, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r6\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r9, r15\n\t"  ); 
//   asm(  "mov.b r9, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r10\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 4?????? ????????  
//  
//  
//  
//     asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////5 round ????
//  asm(  "mov.b  r6,    r15\n\t"  ); 
//  asm("mov.b    r6, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r7\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r10,    r15\n\t"  ); 
//  asm(  "mov.b  r10,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r11\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r4, r15\n\t"  );
//   asm(  "mov.b r4, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r5\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r8, r15\n\t"  ); 
//   asm(  "mov.b r8, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r9\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 5?????? ????????  
// 
//  
//  
//       asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////6round ????
//  asm(  "mov.b  r5,    r15\n\t"  ); 
//  asm("mov.b    r5, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r6\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r9,    r15\n\t"  ); 
//  asm(  "mov.b  r9,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r10\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r11, r15\n\t"  );
//   asm(  "mov.b r11, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r4\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r7, r15\n\t"  ); 
//   asm(  "mov.b r7, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r8\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 6?????? ????????
//  
//  
//         asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////7round ????
//  asm(  "mov.b  r4,    r15\n\t"  ); 
//  asm("mov.b    r4, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r5\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r8,    r15\n\t"  ); 
//  asm(  "mov.b  r8,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r9\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r10, r15\n\t"  );
//   asm(  "mov.b r10, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r11\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r6, r15\n\t"  ); 
//   asm(  "mov.b r6, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r7\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 7?????? ????????
//  
//  
//  
//           asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////8round ????
//  asm(  "mov.b  r11,    r15\n\t"  ); 
//  asm("mov.b    r11, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r4\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r7,    r15\n\t"  ); 
//  asm(  "mov.b  r7,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r8\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r9, r15\n\t"  );
//   asm(  "mov.b r9, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r10\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r5, r15\n\t"  ); 
//   asm(  "mov.b r5, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r6\n\t");      
//  //X[i6] ?? ???? ???? ???? 
//  
//  
////////////////////////////////////////////////////////////////////////////////// 8?????? ????????
//  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  /////////////////////////////////////////////////////////////////////////////////////////////////////////////// 1set ??
//  
//  
//  asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
//  
//  
//  
//    
////1round ???? : r11 = i0,,,r4 = i7, ?????? sk0~3 <==>  0x8(13)~0xb(r13)
//  asm(  "mov.b  r10,    r15\n\t"  ); 
//  asm("mov.b    r10, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r11\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r6,    r15\n\t"  ); 
//  asm(  "mov.b  r6,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r7\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r8, r15\n\t"  );
//   asm(  "mov.b r8, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r9\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r4, r15\n\t"  ); 
//   asm(  "mov.b r4, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r5\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 1?????? ????????
//
//  
//  
//    
//  asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
////2round ????
//  asm(  "mov.b  r9,    r15\n\t"  ); 
//  asm("mov.b    r9, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r10\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r5,    r15\n\t"  ); 
//  asm(  "mov.b  r5,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r6\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r7, r15\n\t"  );
//   asm(  "mov.b r7, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r8\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r11, r15\n\t"  ); 
//   asm(  "mov.b r11, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r4\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 2?????? ????????  
//
//  
//  
//  
//  
// asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
////3round ????
//  asm(  "mov.b  r8,    r15\n\t"  ); 
//  asm("mov.b    r8, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r9\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r4,    r15\n\t"  ); 
//  asm(  "mov.b  r4,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r5\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r6, r15\n\t"  );
//   asm(  "mov.b r6, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r7\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r10, r15\n\t"  ); 
//   asm(  "mov.b r10, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r11\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 3?????? ????????  
//
//  
//  
//  
//  
//   asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////4round ????
//  asm(  "mov.b  r7,    r15\n\t"  ); 
//  asm("mov.b    r7, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r8\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r11,    r15\n\t"  ); 
//  asm(  "mov.b  r11,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r4\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r5, r15\n\t"  );
//   asm(  "mov.b r5, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r6\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r9, r15\n\t"  ); 
//   asm(  "mov.b r9, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r10\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 4?????? ????????  
//  
//  
//  
//     asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////5 round ????
//  asm(  "mov.b  r6,    r15\n\t"  ); 
//  asm("mov.b    r6, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r7\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r10,    r15\n\t"  ); 
//  asm(  "mov.b  r10,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r11\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r4, r15\n\t"  );
//   asm(  "mov.b r4, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r5\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r8, r15\n\t"  ); 
//   asm(  "mov.b r8, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r9\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 5?????? ????????  
// 
//  
//  
//       asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////6round ????
//  asm(  "mov.b  r5,    r15\n\t"  ); 
//  asm("mov.b    r5, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r6\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r9,    r15\n\t"  ); 
//  asm(  "mov.b  r9,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r10\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r11, r15\n\t"  );
//   asm(  "mov.b r11, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r4\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r7, r15\n\t"  ); 
//   asm(  "mov.b r7, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r8\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 6?????? ????????
//  
//  
//         asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////7round ????
//  asm(  "mov.b  r4,    r15\n\t"  ); 
//  asm("mov.b    r4, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r5\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r8,    r15\n\t"  ); 
//  asm(  "mov.b  r8,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r9\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r10, r15\n\t"  );
//   asm(  "mov.b r10, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r11\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r6, r15\n\t"  ); 
//   asm(  "mov.b r6, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r7\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 7?????? ????????
//  
//  
//  
//           asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////8round ????
//  asm(  "mov.b  r11,    r15\n\t"  ); 
//  asm("mov.b    r11, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r4\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r7,    r15\n\t"  ); 
//  asm(  "mov.b  r7,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r8\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r9, r15\n\t"  );
//   asm(  "mov.b r9, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r10\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r5, r15\n\t"  ); 
//   asm(  "mov.b r5, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r6\n\t");      
//  //X[i6] ?? ???? ???? ???? 
//  
//  
////////////////////////////////////////////////////////////////////////////////// 8?????? ????????
//  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  /////////////////////////////////////////////////////////////////////////////////////////////////////////////// 2set ??
//  
//  
//  asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
//  
//    
////1round ???? : r11 = i0,,,r4 = i7, ?????? sk0~3 <==>  0x8(13)~0xb(r13)
//  asm(  "mov.b  r10,    r15\n\t"  ); 
//  asm("mov.b    r10, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r11\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r6,    r15\n\t"  ); 
//  asm(  "mov.b  r6,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r7\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r8, r15\n\t"  );
//   asm(  "mov.b r8, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r9\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r4, r15\n\t"  ); 
//   asm(  "mov.b r4, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r5\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 1?????? ????????
//
//  
//  
//    
//  asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
////2round ????
//  asm(  "mov.b  r9,    r15\n\t"  ); 
//  asm("mov.b    r9, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r10\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r5,    r15\n\t"  ); 
//  asm(  "mov.b  r5,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r6\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r7, r15\n\t"  );
//   asm(  "mov.b r7, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r8\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r11, r15\n\t"  ); 
//   asm(  "mov.b r11, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r4\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 2?????? ????????  
//
//  
//  
//  
//  
// asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
////3round ????
//  asm(  "mov.b  r8,    r15\n\t"  ); 
//  asm("mov.b    r8, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r9\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r4,    r15\n\t"  ); 
//  asm(  "mov.b  r4,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r5\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r6, r15\n\t"  );
//   asm(  "mov.b r6, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r7\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r10, r15\n\t"  ); 
//   asm(  "mov.b r10, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r11\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 3?????? ????????  
//
//  
//  
//  
//  
//   asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////4round ????
//  asm(  "mov.b  r7,    r15\n\t"  ); 
//  asm("mov.b    r7, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r8\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r11,    r15\n\t"  ); 
//  asm(  "mov.b  r11,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r4\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r5, r15\n\t"  );
//   asm(  "mov.b r5, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r6\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r9, r15\n\t"  ); 
//   asm(  "mov.b r9, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r10\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 4?????? ????????  
//  
//  
//  
//     asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////5 round ????
//  asm(  "mov.b  r6,    r15\n\t"  ); 
//  asm("mov.b    r6, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r7\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r10,    r15\n\t"  ); 
//  asm(  "mov.b  r10,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r11\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r4, r15\n\t"  );
//   asm(  "mov.b r4, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r5\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r8, r15\n\t"  ); 
//   asm(  "mov.b r8, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r9\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 5?????? ????????  
// 
//  
//  
//       asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////6round ????
//  asm(  "mov.b  r5,    r15\n\t"  ); 
//  asm("mov.b    r5, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r6\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r9,    r15\n\t"  ); 
//  asm(  "mov.b  r9,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r10\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r11, r15\n\t"  );
//   asm(  "mov.b r11, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r4\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r7, r15\n\t"  ); 
//   asm(  "mov.b r7, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r8\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 6?????? ????????
//  
//  
//         asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////7round ????
//  asm(  "mov.b  r4,    r15\n\t"  ); 
//  asm("mov.b    r4, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r5\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r8,    r15\n\t"  ); 
//  asm(  "mov.b  r8,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r9\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r10, r15\n\t"  );
//   asm(  "mov.b r10, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r11\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r6, r15\n\t"  ); 
//   asm(  "mov.b r6, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r7\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 7?????? ????????
//  
//  
//  
//           asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////8round ????
//  asm(  "mov.b  r11,    r15\n\t"  ); 
//  asm("mov.b    r11, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r4\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r7,    r15\n\t"  ); 
//  asm(  "mov.b  r7,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r8\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r9, r15\n\t"  );
//   asm(  "mov.b r9, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r10\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r5, r15\n\t"  ); 
//   asm(  "mov.b r5, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r6\n\t");      
//  //X[i6] ?? ???? ???? ???? 
//  
//  
////////////////////////////////////////////////////////////////////////////////// 8?????? ????????
//  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  /////////////////////////////////////////////////////////////////////////////////////////////////////////////// 3set ??
//  
//  
//  asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
//  
//  
//  
//  
//    
////1round ???? : r11 = i0,,,r4 = i7, ?????? sk0~3 <==>  0x8(13)~0xb(r13)
//  asm(  "mov.b  r10,    r15\n\t"  ); 
//  asm("mov.b    r10, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r11\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r6,    r15\n\t"  ); 
//  asm(  "mov.b  r6,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r7\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r8, r15\n\t"  );
//   asm(  "mov.b r8, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r9\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r4, r15\n\t"  ); 
//   asm(  "mov.b r4, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r5\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 1?????? ????????
//
//  
//  
//    
//  asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
////2round ????
//  asm(  "mov.b  r9,    r15\n\t"  ); 
//  asm("mov.b    r9, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r10\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r5,    r15\n\t"  ); 
//  asm(  "mov.b  r5,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r6\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r7, r15\n\t"  );
//   asm(  "mov.b r7, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r8\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r11, r15\n\t"  ); 
//   asm(  "mov.b r11, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r4\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 2?????? ????????  
//
//  
//  
//  
//  
// asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
////3round ????
//  asm(  "mov.b  r8,    r15\n\t"  ); 
//  asm("mov.b    r8, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r9\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r4,    r15\n\t"  ); 
//  asm(  "mov.b  r4,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r5\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r6, r15\n\t"  );
//   asm(  "mov.b r6, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r7\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r10, r15\n\t"  ); 
//   asm(  "mov.b r10, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r11\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 3?????? ????????  
//
//  
//  
//  
//  
//   asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////4round ????
//  asm(  "mov.b  r7,    r15\n\t"  ); 
//  asm("mov.b    r7, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r8\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r11,    r15\n\t"  ); 
//  asm(  "mov.b  r11,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r4\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r5, r15\n\t"  );
//   asm(  "mov.b r5, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r6\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r9, r15\n\t"  ); 
//   asm(  "mov.b r9, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r10\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 4?????? ????????  
//  
//  
//  
//     asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////5 round ????
//  asm(  "mov.b  r6,    r15\n\t"  ); 
//  asm("mov.b    r6, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r7\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r10,    r15\n\t"  ); 
//  asm(  "mov.b  r10,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r11\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r4, r15\n\t"  );
//   asm(  "mov.b r4, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r5\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r8, r15\n\t"  ); 
//   asm(  "mov.b r8, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r9\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 5?????? ????????  
// 
//  
//  
//       asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////6round ????
//  asm(  "mov.b  r5,    r15\n\t"  ); 
//  asm("mov.b    r5, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r6\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r9,    r15\n\t"  ); 
//  asm(  "mov.b  r9,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r10\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r11, r15\n\t"  );
//   asm(  "mov.b r11, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r4\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r7, r15\n\t"  ); 
//   asm(  "mov.b r7, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r8\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 6?????? ????????
//  
//  
//         asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////7round ????
//  asm(  "mov.b  r4,    r15\n\t"  ); 
//  asm("mov.b    r4, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r5\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r8,    r15\n\t"  ); 
//  asm(  "mov.b  r8,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r9\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r10, r15\n\t"  );
//   asm(  "mov.b r10, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r11\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r6, r15\n\t"  ); 
//   asm(  "mov.b r6, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r7\n\t");      
//  //X[i6] ?? ???? ???? ???? 
////////////////////////////////////////////////////////////////////////////////// 7?????? ????????
//  
//  
//  
//           asm("add.w #0x04, r13\n\t"  );    //???? ???? 4?? ???? ?????????? ???? ???? ??????
/////////////////////////////////////////////////////////////////////////////////8round ????
//  asm(  "mov.b  r11,    r15\n\t"  ); 
//  asm("mov.b    r11, r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0xb(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r4\n\t");      
//  //X[i0] ?? ???? ???? ????//////////////////
//  
//  
//  
//  asm(  "mov.b  r7,    r15\n\t"  ); 
//  asm(  "mov.b  r7,    r14\n\t"  ); 
//  
//  asm("clrc\n\t");
//    asm("rrc.b     r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//  asm("clrc\n\t");
//   asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b        r14,   r15\n\t");
//  
//  asm("clrc\n\t");
//    asm(    "rlc.b        r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
//  
//  asm(   "add.b  0x9(r13),       r15 \n\t");
//  asm(    "xor.b         r15,    r8\n\t");      
//  //X[i4] ?? ???? ???? ????/////////////////////
//  
//  
//   asm(  "mov.b r9, r15\n\t"  );
//   asm(  "mov.b r9, r14\n\t"  ); 
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");  // <<6
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<3
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t"); // <<4
//  
//  asm(    "xor.b r14, r15\n\t");   
// 
//  asm(   "xor.b 0xa(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r10\n\t");      
//  //X[i2] ?? ???? ???? ???? 
//  
//  
//  
//   asm(  "mov.b r5, r15\n\t"  ); 
//   asm(  "mov.b r5, r14\n\t"  );
//   
//    asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
// 
//   asm("clrc\n\t");
//  asm("rrc.b r15 \n\t");
//  asm("mov.b    #0,        r12\n\t");
//  asm("rrc.b    r12\n\t");
//  asm("xor.b    r12,    r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t");
//  
//   asm("clrc\n\t");
//  asm(    "rlc.b r14 \n\t");
//  asm("addc.b   #0,       r14\n\t");
//  
//  asm(    "xor.b r14, r15\n\t"); 
// 
//  asm(   "xor.b 0x8(r13), r15 \n\t");
//  
//  asm(    "add.b r15, r6\n\t");      
//  //X[i6] ?? ???? ???? ???? 
//  
//  
////////////////////////////////////////////////////////////////////////////////// 8?????? ????????
//  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  /////////////////////////////////////////////////////////////////////////////////////////////////////////////// 4set ??
//
//  
//  
//  
//////////////////////////////////////////????
//  
//  asm( " sub.w #0x7c, r13\n\t");  
//  
//  asm(" add.b 0x4(r13), r5\n\t");  
//  asm(" xor.b 0x5(r13), r7\n\t");  
//  asm(" add.b 0x6(r13), r9\n\t");  
//  asm(" xor.b 0x7(r13), r11\n\t");   
//
//  asm("pop.w r12\n\t");
//  asm("mov.b r5, 0x0(r12)\n\t");
//  asm("mov.b r6, 0x1(r12)\n\t");
//  asm("mov.b r7, 0x2(r12)\n\t");
//  asm("mov.b r8, 0x3(r12)\n\t");
//  asm("mov.b r9, 0x4(r12)\n\t");
//  asm("mov.b r10, 0x5(r12)\n\t");
//  asm("mov.b r11, 0x6(r12)\n\t");
//  asm("mov.b r4, 0x7(r12)\n\t");
//  
//}
//
//
//
//
//int main(void)
//{
//    unsigned char use_key[136] = { 0, };						
//    unsigned char masterkey[16] = { 0x88, 0xE3, 0x4F, 0x8F, 0x08, 0x17, 0x79,0xF1, 0xE9, 0xF3, 0x94, 0x37, 0x0A, 0xD4, 0x05, 0x89 }; 		
//    unsigned char plaintext[8] = { 0xD7, 0x6D, 0x0D,0x18, 0x32, 0x7E, 0xC5, 0x62 }; 		
//    HIGHT_keygen(masterkey, use_key );
//    asm_hight_enc(plaintext, use_key);
//    
//    return 0;
//}