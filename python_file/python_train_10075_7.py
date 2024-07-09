n,s=map(int,input().split())
dp=[0]*(s+1)
mod=998244353
inv=pow(2,mod-2,mod)
dp[0]=pow(2,n,mod)
for i in list(map(int,input().split())):
  for j in range(s,i-1,-1):
    dp[j]=(dp[j]+dp[j-i]*inv)%mod
print(dp[s])