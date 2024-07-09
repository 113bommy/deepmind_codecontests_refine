n,k=map(int,input().split())
a=list(map(int,input().split()))
mod=1000000007
dp=[[0]*(k+1) for i in range(n+1)] 
dp[0][0]=1
for i in range(n):
  sm=0
  for j in range(k+1):
    sm+=dp[i][j]
    sm%=mod
    dp[i+1][j]=sm
    if j>=a[i]:
      sm-=dp[i][j-a[i]]
      sm=(sm+mod)%mod
print(dp[n][k])