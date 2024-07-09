N, Ma, Mb = map(int, input().split())
abc = [list(map(int, input().split())) for i in range(N)]
INF = 10**5
n = 10*N + 1
dp = [[[INF]*n for i in range(n)] for j in range(N+1)]
dp[0][0][0] = 0

for i, (a, b, c) in enumerate(abc, 1):
  for j in range(n):
    for k in range(n):
      dp[i][j][k] = dp[i-1][j][k]
      if a <= j and b <= k:
        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-a][k-b]+c)

ans = INF
dp[-1][0][0] = INF
for j in range(n):
  for k in range(n):
    if j * Mb == k*Ma:
      ans = min(ans, dp[-1][j][k])

if ans < INF:
  print(ans)
else:
  print(-1)