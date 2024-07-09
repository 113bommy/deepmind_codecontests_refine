n,k=map(int,input().split())
h=list(map(int,input().split()))
dp=[10**9]*n
dp[0]=0

for i in range(n):
  a=max(0,i-k)
  for j in range(a,i):
    dp[i]=min(dp[i],dp[j]+abs(h[i]-h[j]))
print(dp[-1])