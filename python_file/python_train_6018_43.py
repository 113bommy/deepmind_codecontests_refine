S = input()
MOD = 10 ** 9 + 7
N = len(S)

dp = [[0 for _ in range(13)] for _ in range(N + 1)]
dp[0][0] = 1

for i in range(N):
    for j in range(0, 10):
        if (S[i] != '?' and S[i] != str(j)):
            continue
        for k in range(0, 13):
            dp[i + 1][(k * 10 + j) % 13] += dp[i][k]

    for j in range(0, 13):
        dp[i + 1][j] %= MOD

print(dp[N][5])
