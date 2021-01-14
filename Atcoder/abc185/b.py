cur, n, m= list(map(int, input().split()))
cap = cur

ar = []
for i in range(n):
    ar.append(list(map(int, input().split())))

prev = 0
fl = 0
for i in range(n):
    cur -= (ar[i][0] - prev)
    if cur <= 0:
        fl = 1
    cur += (ar[i][1] - ar[i][0])
    cur = min(cur, cap)
    if cur <=  0 :
        fl = 1
    prev = ar[i][1]

cur -= (m - ar[-1][1])

if cur <=  0:
    fl = 1


if fl:
    print('No')
else:
     print('Yes')