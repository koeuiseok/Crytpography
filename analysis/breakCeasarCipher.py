#-----------------
# 암호분석 2020
#-----------------

#---Ceasar Cipher Library
import os, sys

in_file = 'my_text.txt'
if not os.path.exists(in_file):
    print('File %s does not exist', %(in_file))
    sys.exit()
    