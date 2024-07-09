s = list(input().rstrip())
n = len(s)
m = 10 ** 9 + 7
dp = [[0] * 13 for _ in range(n + 1)]
dp[0][0] = 1

for i in range(n):
    c = -1 if s[i] == '?' else int(s[i])
    for j in range(10):
        if c != -1 and c != j:
            continue
        for ki in range(13):
            dp[i + 1][(ki * 10 + j) % 13] += dp[i][ki]
        for j in range(13):
            dp[i + 1][j] %= m
print(dp[n][5])
