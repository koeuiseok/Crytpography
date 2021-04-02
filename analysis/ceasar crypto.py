#--------------
# 암호분석 2020
#---------------

#Ceasar Ciper

lower_alphabet = "abcdefghijklmnopqrstuvwxyz"
upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#--평문(plaintext)

plain_msg = " This is a plaintext message to be ecrypted"

#---암호키
key = 3

#--암호화 과정
ciper_msg = ""
for symbol in plain_msg:
    if symbol in upper_alphabet:
        symbol_idx = upper_alphabet.find(symbol)
        trans_idx = (symbol_idx + key) % len(upper_alphabet)
        ciper_msg = ciper_msg + upper_alphabet[trans_idx]
    elif symbol in lower_alphabet: #소문자인 경우
        symbol_idx = lower_alphabet.find(symbol)
        trans_idx = (symbol_idx + key) % len(lower_alphabet)
        ciper_msg = ciper_msg + lower_alphabet[trans_idx]
    else: #영문자가 아닌 경우
        ciper_msg = ciper_msg + symbol
print("plaintext =", plain_msg)
print("cipertext =", ciper_msg)

#--- 복호화 과정
recovered_msg=""
for symbol in ciper_msg:
    if symbol in upper_alphabet:
        symbol_idx = upper_alphabet.find(symbol)
        trans_idx = (symbol_idx - key) % len(upper_alphabet)
        recovered_msg = recovered_msg + upper_alphabet[trans_idx]
    elif symbol in lower_alphabet: #소문자인 경우
        symbol_idx = lower_alphabet.find(symbol)
        trans_idx = (symbol_idx - key) % len(lower_alphabet)
        recovered_msg = recovered_msg + lower_alphabet[trans_idx]
    else: #영문자가 아닌 경우
       recovered_msg = recovered_msg + symbol
print("recovered text = ", recovered_msg)