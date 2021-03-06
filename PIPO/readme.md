# PIPO block cipher

## PIPO (Plug In Plug Out)이란?
  ### : 2020년 제작된 국산 암호알고리즘
  ### : 차분, 선형 공격으로 부터 안전하게 설계  => 안전성의 척도인 차분, 선형에 대한 branch number를 일정 수준(level 3)이상
  ### : bitslicing을 기반으로 SBOX 연산시 사전연산(Table) 없이도 그보다 더 빠른 구현 가능
  ### : 경량화 된 sbox 연산으로 기존의 블록암호들 보다 연산량이 줄어듬
  ### : 기존의 경량암호의 ARX 구조와 달리 SPN 구조를 택함
  
## 구현코드 
  ### : 임베디드 환경인, MSP430 환경에서 Code Composer Studio를 사용하여 구현한 코드
  ### : 기존에 공개된 코드(PIPO 공식 코드)보다 속도를 2~3배 향상시킨 코드 2개(Inline~.c) & 부채널 공격의 일종인 차분오류주입공격에 대응하며 속도 또한 향상시킨 코드(PIPO_against_DFA.c)
  ### : 암호화 부분을 Inline Assembly로 구현해, 속도를 향상
  ### : 레지스터에 평문블록을 넣는 것과 병렬연산을 중심으로 작성
  ### : 중복데이터를 활용해 차분오류주입 공격에 대응
