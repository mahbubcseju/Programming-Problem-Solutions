n , m, c = map(int, input().split())
br = list(map(int, input().split()))

res = 0
for i in range(n):
    print(i)
    ar = list(map(int, input().split()))
    print(i)
    ans = c
    for j in range(m):
        ans += ar[j] * br[j]
    if ans > 0:
        res += 1

print(res)