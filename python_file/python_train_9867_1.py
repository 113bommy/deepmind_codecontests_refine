a, b, c, d = map(int,input().split())
dp = [[0 for j in range(d+1)] for i in range(c+1)]
for i in range(a, c+1):
  for j in range(b, d+1):
    if i == a and j == b:
      dp[i][j] = 1
      continue
    dp[i][j] = (dp[i-1][j] * j + dp[i][j-1] * i - dp[i-1][j-1] * (i-1) * (j-1) ) % 998244353
    dp[i][j] += 998244353
    dp[i][j] %= 998244353
print(dp[c][d])