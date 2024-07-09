S = input()
N = len(S)
MOD = 10 ** 9 + 7

dp = [[0] * 13 for _ in range(N + 1)]
dp[0][0] = 1
for i in range(N):
    c = int(S[i]) if S[i] != "?" else -1
    for j in range(10):
        if c == -1 or c == j:
            for ki in range(13):
                dp[i+1][(ki * 10 + j) % 13] += dp[i][ki]
    for j in range(13):
        dp[i+1][j] %= MOD
ans = dp[N][5]
print(ans)