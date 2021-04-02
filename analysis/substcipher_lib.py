

Alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def encrypt(key, msg):
    result = ''
    Inset = Alphabet
    Outset = key

    for ch in msg:
        if ch.upper() in Inset:
            idx = Inset.find(ch.upper())
            if ch.isupper():
                result = result + Outset[idx].upper()
            else:
                result = result + Outset[idx].lower()
        else:
            result += ch
        
    return result

def decrypt(key, msg):
    result = ''
    Inset = key
    Outset = Alphabet

    for ch in msg:
        if ch.upper() in Inset:
            idx = Inset.find(ch.upper())
            if ch.isupper():
                result += Outset[idx].upper()
            else:
                result += Outset[idx].lower()
        else:
            result += ch
        
    return result


key = 'VWXABCDEFGHIJKLMNOPQRSTUYZ'
msg = 'This is an online class'
cipher_msg = encrypt(key, msg)
print(msg)
print(cipher_msg)
recovered_msg =  decrypt(key, cipher_msg)
print(recovered_msg)

