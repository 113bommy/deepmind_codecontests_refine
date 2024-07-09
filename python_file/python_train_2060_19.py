s = input()
dp = [[0, 0] for i in range(len(s))]
dp[0][0] = int(s[0])
dp[0][1] = 11 - int(s[0])
for i in range(1, len(s)):
  dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + int(s[i])
  dp[i][1] = min(dp[i - 1][0] + 11 - int(s[i]), dp[i - 1][1] + 9 - int(s[i]))
print(min(dp[-1][0], dp[-1][1]))