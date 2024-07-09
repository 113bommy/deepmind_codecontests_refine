n,m=map(int,input().split())
s=list(map(int,input().split()))
t=list(map(int,input().split()))
dp=[[0]*(m+1) for _ in range(n+1)]
for i in range(n+1):
  dp[i][0]=1
for i in range(m+1):
  dp[0][i]=1
mod=pow(10,9)+7
for i in range(n):
  for j in range(m):
    dp[i+1][j+1]=sum((dp[i][j+1],dp[i+1][j],-dp[i][j]))%mod
    if s[i]==t[j]:dp[i+1][j+1]+=dp[i][j]
    dp[i+1][j+1]%=mod
print(dp[-1][-1])
#print(dp)