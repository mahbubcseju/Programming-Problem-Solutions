n = int(input())

if n  == 1:
    print(1)
    break
ans = 0
for j in range(1, n + 1):
    k = j
    for i in range(2, n + 1):
        k = k * j
        if k > n:
            break
        ans = max(ans, k)


print(ans)