#-------------------
# 암호분석 2020
#-------------------

import random
S = [0,2,3,5,4,7,6,1]
DT=[]
for b in range(len(S)):
    DT.append([0 for j in range(len(S))])

for a in range(len(S)):
    for x1 in range(len(S)):
        z=S[x1]^S[x1^a]
        DT[a][z]=DT[a][z]+1

for i in range(len(S)):
    print(DT[i]) 


    
    
    
    