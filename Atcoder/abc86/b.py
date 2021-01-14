a = input()
a = a.replace(' ', '')

a = int(a)
import math
x = int(math.sqrt(a))

for j in range( x- 2, x + 3):
    if j * j == a:
        print("Yes")
        exit()

print("No")