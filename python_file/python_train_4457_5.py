n, k = map(int, input().split())
m = n**2
mod = 10**9+7
dp = [[[0]*(m+1) for j in range(i+1)] for i in range(n+1)]
dp[0][0][0] = 1
for i in range(n):
  for j in range(i+1):
    for l in range(m+1):
      dp[i][j][l] %= mod
      if j and l+2*(j-1) <= m:
        dp[i+1][j-1][l+2*(j-1)] += dp[i][j][l]*j**2
      if l+2*j <= m:
        dp[i+1][j][l+2*j] += dp[i][j][l]*(2*j+1)
        if l+2*(j+1) <= m: 
          dp[i+1][j+1][l+2*(j+1)] += dp[i][j][l]
ans = dp[n][0][k]%mod
print(ans)