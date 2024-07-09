N, S = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353
dp = [[0]*(S+1) for _ in range(N+1)]
dp[0][0] = 1
for i in range(N):
    for s in range(S+1):
        if s-A[i] >= 0:
            dp[i+1][s] = (dp[i][s] * 2 + dp[i][s-A[i]]) % MOD
        else:
            dp[i+1][s] = dp[i][s] * 2 % MOD
print(dp[N][S])

