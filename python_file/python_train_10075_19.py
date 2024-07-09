N,S=map(int,input().split())
ls=list(map(int,input().split()))
MOD=998244353
dp=[[1]+[0]*S for i in range(N+1)]
for i in range(N):
  for j in range(S+1):    
      dp[i+1][j]=dp[i][j]*2%MOD
      if ls[i]<=j:
        dp[i+1][j]=(dp[i+1][j]+dp[i][j-ls[i]])%MOD
print(dp[N][S])