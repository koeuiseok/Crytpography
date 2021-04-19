## 2020 동계정보보호학회 논문 코드 : HIGHT_assemble_with_msp430
HIGHT_ENCRYPTION_implement_assembly_with_16bit_msp430


HIGHT 암호화 과정을 16 bit msp 환경에서 구현을 하였다.
4가지 버전을 작성하였다.
F0,F1을 직접 계산하여 메모리 최적화를 한 'HIGHT_no_use_table'
F0, F1함수를 사전계산으로table화하여 구현 속도를 올린 'HIGHT_use_table'.
'HIGHT'의 8bit씩 처리하는 과정을 16bit씩 처리하게 만든 'HIGHT_use_table_with_2_plaintext'
논문용 코드인 hight_against_default_attack 로 구성된다


use IAR IDE. (You must change the code to use it in CCS. Because compilers are different)
