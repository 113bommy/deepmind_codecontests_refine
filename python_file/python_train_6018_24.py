S=input()
l=len(S)
mod=10**9+7
dp=[[0 for j in range(13)] for i in range(l+1)]
dp[0][0]=1

for i in range(l):
  if S[i]=='?':
    for k in range(13): 
      for j in range(10):      
        dp[i+1][(k*10+j)%13]+=dp[i][k]%mod
  else:
    for k in range(13):
      dp[i+1][(k*10 + int(S[i]))%13]+=dp[i][k]%mod
      
print(dp[-1][5]%mod)