n = int(input())

res = n

def ache(x, b):
    while x:
        mo = x % b
        if mo == 7:
            return True
        x //= b
    return False


for i in range(1, n + 1):
    if ache(i, 10) or ache(i, 8):
        res -= 1

print(res)