import math
a,b =map(int,input().split())

n=int(math.sqrt(a))

res=0

for i in range(1,b):
    if(i*i+i>b):
        break
    else :
        res+=1
        
if(n<=res):
    print("Vladik")
    
else:
    print("Valera")
