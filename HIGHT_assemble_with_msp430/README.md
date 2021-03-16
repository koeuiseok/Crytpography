# HIGHT_assemble_with_msp430
HIGHT_ENCRYPTION_implement_assembly_with_16bit_msp430


HIGHT 암호화 과정을 16 bit msp환경해서 구현을 하였다.
구현은 3가지 방식으로 하여 따로따로 작성하였다.
F0,F1을 직접 계산하여 메모리 최적화를 한 'HIGHT_no_use_table'
F0, F1함수를 사전계산으로table화하여 구현 속도를 올린 'HIGHT_use_table'.
'HIGHT'의 8bit씩 처리하는 과정을 16bit씩 처리하게 만든 'HIGHT_use_table_with_2_plaintext'로 구성된다.
