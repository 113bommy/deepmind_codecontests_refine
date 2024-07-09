MOD = 998244353
N, S = map(int, input().split())
A = list(map(int, input().split()))
dp = [[0] * (S + 1) for _ in range(N+1)]
dp[0][0] = 1
for i in range(N):
    a = A[i]
    for j in range(S+1):
        dp[i+1][j] += dp[i][j] * 2
        dp[i+1][j] %= MOD
        if j + a <= S:
            dp[i+1][j+a] += dp[i][j]
            dp[i+1][j+a] %= MOD
print(dp[N][S])
