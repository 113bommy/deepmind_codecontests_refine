N, A = map(int, input().split())
x = [int(i) for i in input().split()]
ans = 0

dp = [[[0]*(50*N+1) for j in range(N+1)] for k in range(N+1)]
dp[0][0][0] = 1 
for j in range(1,N+1):
  for k in range(N+1):
    for s in range(50*N+1):
      dp[j][k][s] = dp[j-1][k][s]
      if s>=x[j-1]:
        dp[j][k][s] += dp[j-1][k-1][s-x[j-1]]
for k in range(1,N+1):
  ans += dp[N][k][k*A]
print(ans)