import os
os.chdir('../')
os.chdir(os.path.dirname(os.path.abspath(__file__)))

import toy_cipher_TC20
import TC20_Dec_lib

message = 'gfne'
key = [0, 2, 6, 7]
input_state = [ ord(ch) for ch in message ]

output_state = [ item for item in TC20_Enc(input_state, key)  ]
print('message =', message)
print('input plaintext =', input_state)
print('output ciphertext =', output_state)

output_state_Dec = [ item for item in TC20_Dec(output_state, key)  ]
msg1 = [chr(ch) for ch in output_state_Dec]
print('output plaintext =', output_state_Dec)
print('plain message = ', msg1)

