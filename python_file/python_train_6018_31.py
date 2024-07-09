s = input()
divisor = 10 ** 9 + 7
dp = [[0] * 13 for _ in range(len(s) + 1)]
dp[0][0] = 1
for i in range(len(s)):
  if s[i] == '?':
    for j in range(10):
      for k in range(13):
        dp[i + 1][(k * 10 + j) % 13] += dp[i][k]
  else:
    t = int(s[i])
    for k in range(13):
      dp[i + 1][(k * 10 + t) % 13] += dp[i][k]
  for k in range(13):
    dp[i + 1][k] %= divisor
print(dp[len(s)][5])
