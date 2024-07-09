N, K = map(int, input().split())
H = [0] + list(map(int, input().split()))

INF = 10**12
dp = [[INF] * (N+1) for i in range(N+1)]
dp[0][0] = 0

for x in range(1, N+1):
  dp[x][0] = 0
  dp[x][1] = H[x]
  for y in range(2, x+1):
    for i in range(x):
      dp[x][y] = min(dp[x][y], dp[i][y-1]+max(0, H[x]-H[i]))

ans = INF
for i in range(N+1):
  ans = min(ans, dp[i][N-K])

print(ans)