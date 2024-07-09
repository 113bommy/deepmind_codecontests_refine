intLine=lambda:map(int,input().split())
h,n=intLine()
dp=[10**9]*(h+1)
dp[0]=0
for _ in range(n):
  a,b=intLine()
  for j in range(h+1):
    dp[j]=min(dp[j],dp[max(0,j-a)]+b)
print(dp[h])