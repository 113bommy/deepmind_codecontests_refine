N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
MOD = 10**9 + 7

dp = [[0] * (M + 1) for _ in range(N + 1)]
for i in range(N + 1):
    dp[i][0] = 1
for j in range(M + 1):
    dp[0][j] = 1

for i, a in enumerate(A, start=1):
    for j, b in enumerate(B, start=1):
        if a == b:
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD
        else:
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % MOD

print(dp[N][M])
