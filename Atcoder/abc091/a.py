n = int(input())
ar = [0] * n

mp, mp1 = {}, {}
for i in range(n):
    ar[i] = input()
    if ar[i] in mp:
        mp[ar[i]] += 1
    else:
        mp[ar[i]] = 1

m = int(input())
br = [0] * m

for j in range(m):
    br[j] = input()
    mp1[br[j]] = mp1[br[j]] + 1 if br[j] in mp1 else 1


res = 0

for i in range(n):
    res = max(res, mp[ar[i]] - ( mp1[ar[i]] if ar[i] in mp1 else 0))

print(res)