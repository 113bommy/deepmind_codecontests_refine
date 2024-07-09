MOD=10**9+7

N,M=map(int,input().split())
slist=list(map(int,input().split()))
tlist=list(map(int,input().split()))

dp,dp_sum=[],[]
for i in range(N+1):
  dp.append([0]*(M+1))
  dp_sum.append([1]*(M+1))
dp[0][0]=1
#print(dp)

for i in range(1,N+1):
  for j in range(1,M+1):
    if slist[i-1]==tlist[j-1]:
      dp[i][j]=dp_sum[i-1][j-1]      
    dp_sum[i][j]=(dp[i][j]+dp_sum[i-1][j]+dp_sum[i][j-1]-dp_sum[i-1][j-1])%MOD
#print(dp)
#print(dp_sum)

print(dp_sum[-1][-1])