S = input()
T = input()

dp = [[0] * (len(T)+1) for i in range(len(S)+1)]
for i, s in enumerate(S, 1):
  for j, t in enumerate(T, 1):
    if s == t:
      dp[i][j] = dp[i-1][j-1] + 1
    else:
      dp[i][j] = max(dp[i-1][j], dp[i][j-1])

ans = ''
while i > 0 and j > 0:
  if dp[i][j] == dp[i][j-1]:
    j -= 1
  elif dp[i][j] == dp[i-1][j]:
    i -= 1
  else:
    ans += S[i-1]
    i -= 1
    j -= 1

print(ans[::-1])