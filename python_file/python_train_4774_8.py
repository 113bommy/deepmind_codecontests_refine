N, Ma, Mb = map(int,input().split())
C = [map(int,input().split()) for i in range(N)]
INF = 40000
dp = [[[INF]*401 for i in range(401)] for i in range(N+1)]
dp[0][0][0] = 0
for i in range(1,N+1):
  a,b,c = C[i-1]
  for j in range(401):
      for k in range(401):
        dp[i][j][k] = dp[i-1][j][k]
        if j >= a and k >= b and dp[i-1][j-a][k-b] != INF:
            dp[i][j][k] = min(dp[i][j][k],dp[i-1][j-a][k-b]+c)
ans = INF
Ma2,Mb2 = Ma,Mb
while max(Ma2,Mb2) < 401:
  ans = min(ans,dp[-1][Ma2][Mb2])
  Ma2 += Ma
  Mb2 += Mb    

print(ans if ans != INF else -1)
