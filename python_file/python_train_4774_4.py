n,ma,mb=map(int,input().split())
dp=[[[9999]*401for _ in range(401)]for _ in range(n+1)];dp[0][0][0]=0
sa=sb=0
for i in range(1,n+1):
  a,b,c=map(int,input().split())
  sa+=a;sb+=b
  for j in range(401):
    for k in range(401):
      if j>=a and k>=b:dp[i][j][k]=min(dp[i-1][j-a][k-b]+c,dp[i-1][j][k])
      else:dp[i][j][k]=dp[i-1][j][k]
a=9999
for i in range(1,min(sa//ma,sb//mb)+1):
  if dp[n][ma*i][mb*i]!=9999:a=min(a,dp[n][ma*i][mb*i])
print(-1if a==9999else a)