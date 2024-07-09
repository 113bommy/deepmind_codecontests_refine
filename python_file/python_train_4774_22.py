n,ma,mb=map(int,input().split())
dp=[[[5000]*401for _ in range(401)] for _ in range(n+1)]
dp[0][0][0]=0
maa=mab=0
for i in range(1,n+1):
  a,b,c=map(int,input().split())
  maa+=a
  mab+=b
  for j in range(401):
    for k in range(401):dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-a][k-b]+c)
ans=5000
for i in range(1,min(maa//ma,mab//mb)+1):
  if dp[n][ma*i][mb*i]!=5000:ans=min(ans,dp[n][ma*i][mb*i])
print(-1if ans==5000else ans)