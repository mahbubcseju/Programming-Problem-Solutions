n = int (input())


dp = [[0] * 13 for i in range(n + 2)]


dp[0][0] = 1
for i in range(1, n + 1):
    for j in range(1, i + 1):
        for k in range(1, 13):
            dp[i][k] += dp[i -j][k-1]

print(dp[n][12])
