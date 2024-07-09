N = int(input())
S = input()
dp = [[0]*(N+1) for i in range(N+1)]
ans = 0
for i in range(N-1,-1,-1):
  for j in range(i,-1,-1):
    if S[i] == S[j]:
      dp[i][j] = dp[i+1][j+1] + 1
      tmp = min(dp[i][j],i-j)
      ans = max(ans,tmp)
print(ans)