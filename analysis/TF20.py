#-------------------------
# 암호분석 2020
#-------------------------

import TC20_Enc_lib

def Enc_Round1(inL, inR, rkey):
    outL = outR =[0]*4
    outR= inL
    outF=TC20_Enc_lib.FRound(inL, rkey)
    for i in range(len(outF)):
        outL[i]=outF[i]^inR[i]
        
    return outL, outR

'''
def Dec_Round1(inL, inR, rkey):
    outL = outR = [0]*4
    outR=inL
    outF=TC20_Enc_lib.FRound(inL, rkey)
    for i in range(len(outF)):
        outL[i] = outF[i]^inR[i]
    return outL, outR
'''

def TF20_Enc1(in_state, key):
    inL = in_state[:4]
    inR=in_state[4:]
    numRound = 16
    
    for i in range(0,numRound):
        inL, inR = Enc_Round1(inL, inR, key)
        
    inL, inR =inR, inL
        
    state = inL+inR
    return state

def main():
    message = 'ABCDEFGH'
    key = [0,1,2,3]
    input_state = [ord(item) for item in message]
    state=TF20_Enc1(input_state, key)
    print('message = ', message)
    print('in_state = ', input_state)  
    print('Enc = ', state)
    recover = TF20_Enc1(state, key)
    print('recovered msg = ', recover)
    
    '''
    outL, outR = Enc_Round1(in_L,in_R, key)
    dec1,dec2 = Dec_Round1(outR,outL,key)
    decrypt = dec2+dec1
    demsg = [chr(a) for a in decrypt]
    remsg =  ''.join(demsg)


    print('dcrypt = ' , decrypt )
    print('recovered = ', remsg)
    '''
    
    
    
if __name__=='__main__':
    main()