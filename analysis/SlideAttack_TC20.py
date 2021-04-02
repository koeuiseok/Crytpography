#-------------------------
# 암호분석 2020
# Slide Attack on TC20 Cipher
#-------------------------

import TC20_Enc_lib as TC20E
import TC20_Dec_lib as TC20D
import pickle    # 변수 저장
import random    # 난수 생성
import copy      # 딥 카피 (깊은 복사) 


#------------------------------------------------
# 변수를 파일에 저장하기 (이전부터 사용하던 함수들)
#------------------------------------------------
def save_var_to_file(var, filename):
    f = open(filename, 'w+b')
    pickle.dump(var, f)
    f.close()
    
#- 파일에서 변수를 가져오기
def load_var_from_file(filename):
    f = open(filename, 'rb')
    var = pickle.load(f)
    f.close()
    return var
#----------------------------------------------

#--------------------------
# 라운드 입출력으로부터 라운드키를 추출하는 함수
# 주어진 A, B에 대하여 
#  F(A, rk) = B
# 를 만족하는 rk를 찾는 함수
#--------------------------
def Extract_RK(A,B):
    in_state= A
    state1 = TC20D.LM(B)
    state2 = TC20D.ISB(state1)
    rk = TC20D.AR(state2, in_state)
    return rk

#--------------------------
# 주어진 두 쌍의 (평문, 암호문)이 Slid pair 인지 확인
# (P1, C1), (P2, C2)
#--------------------------
def IsSlidPair(P1, C1, P2, C2):
    rk = [0,0,0,0]
    flag = False
    
    rk = Extract_RK(P1, P2)
    rnd_out = TC20E.Enc_Round(C1, rk)
    if rnd_out == C2:
        flag = True
    else:
        flag = False
    
    return (flag, rk)


#--------------------------
# 공격예제를 만들기 위한
# Known plaintext-ciphertext (Pi, Ci) 만들기
#--------------------------
def Generate_Known_pt_ct(num_pair, key):
    list_pool = []
    print('Generating PT-CT pairs', end='')
    for i in range(0,num_pair):
        PT = [0, random.randint(0,255), random.randint(0,255), random.randint(0,255)]
        CT = TC20E.TC20_Enc(PT, key)
        item = copy.deepcopy([PT,CT])
        list_pool.append(item)
        if (i % (1<<18)) == 0:
            print('.', end='')
    print('  Done! \n')
    return list_pool

#--------------------------
# Slide Attack    
#--------------------------    
def Slide_Attack(pool):
    key = [0,0,0,0]
    
    print('Start Slide Attack', end='')
    for pair1 in pool:
        P1 = pair1[0]
        C1 = pair1[1]
        for pair2 in pool:
            P2 = pair2[0]
            C2 = pair2[1]
            flag, key = IsSlidPair(P1, C1, P2, C2)
            if flag:
                return (True, key)
        print('.', end='')
    
    print('  Done!\n')
    return (False, [0,0,0,0])
    


'''
#==================================
# (0) Slid Pair 함수 테스트용
#==================================
key = [1, 2, 3, 4]    

P1 = [1, 1, 1, 1]
C1 = TC20E.TC20_Enc(P1, key)
# C1 = [161, 148, 15, 222]
print('P1 =',P1)
print('C1 =',C1)

#P2 = TC20E.Enc_Round(P1, key)
P2 = [103, 127, 115, 111]
C2 = TC20E.TC20_Enc(P2, key)
# C2 = [18, 227, 178, 104]
print('P2 =',P2)
print('C2 =',C2)

print(IsSlidPair(P1, C1, P2, C2))
#==================================
'''

'''
#==================================
# (1) 공격용 예제 (평문, 암호문) 쌍 만들기
#     기지평문을 만들고 파일에 저장 (Slide Attack에 사용할 파일)
#==================================
key = [1, 2, 3, 4]    
pool = Generate_Known_pt_ct(1<<16, key)
#print(pool)
save_var_to_file(pool, 'known_ptct.var')
load_pool = load_var_from_file('known_ptct.var')
#==================================
'''

#==================================
# (2) Slide Attack
#     파일에 저장된 (평문, 암호문) 쌍을 이용하여 암호키 추출 
#==================================
pool = load_var_from_file('known_ptct.var')
result, key = Slide_Attack(pool)
print(result, key)
#==================================


