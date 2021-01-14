s = input()
cnt = 0
res = 0
for i in s:
    if i in ('A', 'C', 'T', 'G'):
        cnt += 1
    else:
        cnt = 0
    res = max(res, cnt)

print(res)