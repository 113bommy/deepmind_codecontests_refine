MOD = 998244353
n, s = map(int, input().split())
A = list(map(int, input().split()))
ans = 0
dp = [[0]*(s+1) for _ in range(n+1)]
dp[0][0] = 1
for i, a in enumerate(A):
    for j in range(s+1):
        if j >= a:
            dp[i+1][j] = dp[i][j]*2 + dp[i][j-a]
        else:
            dp[i+1][j] = dp[i][j]*2
        dp[i+1][j] %= MOD
ans = dp[n][s]
print(ans)