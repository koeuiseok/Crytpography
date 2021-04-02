#---------------
# 암호분석 2020
#---------------

UpAlphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
LowerAlphabet = 'abcdefghijklmnopqrstuvwxyz'

#---Ceasar crypto

def ceasar_encrypt(key, plain_msg):
    cipher_msg = ''
    for symbol in plain_msg:
        if symbol in UpAlphabet:
            symbol_idx = UpAlphabet.find(symbol)
            cipher_msg = cipher_msg \
            + UpAlphabet[(symbol_idx + key)%len(UpAlphabet)]
        elif symbol in LowerAlphabet:
            symbol_idx = LowerAlphabet.find(symbol)
            cipher_msg = cipher_msg \
            + LowerAlphabet [(symbol_idx + key)%len(LowerAlphabet)]
        else:
            cipher_msg = cipher_msg + symbol
    return cipher_msg

def ceasar_decrypt(key, cipher_msg):
   plain_msg = ''
   for symbol in cipher_msg:
       if symbol in UpAlphabet:
            symbol_idx = UpAlphabet.find(symbol)
            plain_msg = plain_msg \
            + UpAlphabet[(symbol_idx - key)%len(UpAlphabet)]
       elif symbol in LowerAlphabet:
            symbol_idx = LowerAlphabet.find(symbol)
            plain_msg = plain_msg \
            + LowerAlphabet [(symbol_idx - key)%len(LowerAlphabet)]
       else:
            plain_msg = plain_msg + symbol
   return plain_msg

#----------------------------------------------------------------------



#-------------테스트용 main()
def main(): 
    plaintext = 'This is a sample.'
    key = 3
    ciphertext = ceasar_encrypt(key, plaintext)
    print('plaintext = ',plaintext)
    print('ciphertext = ', ciphertext)
    recovertext= ceasar_decrypt(key, ciphertext)
    print('recovertext is ', recovertext)
    
#-----------Run main()
if __name__ == '__main__':
    main()
    
    