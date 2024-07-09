s, t = input(), input()
n, m = len(s), len(t)
dp = [[0]*-~m for _ in [0]*-~n]
for i in range(n):
  for j in range(m):
    dp[i+1][j+1] = dp[i][j] + 1 if s[i] == t[j] else max(dp[i][j+1], dp[i+1][j])
R = ""
while n and m:
  if   dp[n][m] == dp[n-1][m]:n -= 1
  elif dp[n][m] == dp[n][m-1]:m -= 1
  else:n -= 1;m -= 1;R = s[n] + R
print(R)