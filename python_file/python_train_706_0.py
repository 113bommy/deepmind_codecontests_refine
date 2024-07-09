n,k=map(int,input().split())
a=list(map(int,input().split()))
dp=[0]*(k+1)
dp[0]=1
mod=10**9+7
for i in range(n):
  for j in range(k,0,-1):
    if j>a[i]:dp[j]-=dp[j-a[i]-1]
  for j in range(k):dp[j+1]=(dp[j+1]+dp[j])%mod
print(dp[k])