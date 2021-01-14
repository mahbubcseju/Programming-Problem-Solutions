s = input()
for i in range(len(s) - 3 + 1):
    f = s[i: i+3]
    if f[0] == f[1] == f[2]:
        print('Yes')
        exit()

print('No')