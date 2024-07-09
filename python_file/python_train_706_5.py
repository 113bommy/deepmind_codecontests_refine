n, k  = map(int, input().split())
A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

# dp[i][j] i人目までの子供にj個のアメを配る数
dp = [[0] * (ｋ + 1) for _ in range(n + 1)]

for i in range(n + 1):
  dp[i][0] = 1
  
for i in range(1, n + 1):
  for j in range(1, k + 1):
    if j-1-A[i-1] >= 0:
      dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1-A[i-1]]) % MOD
    else:
      dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD

ans = dp[n][k]
print(ans)
