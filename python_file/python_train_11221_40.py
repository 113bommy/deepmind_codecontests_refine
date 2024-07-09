import sys
f=lambda:map(int,sys.stdin.readline().split())
h,n=f()
dp=[10**9]*(h+1)
dp[0]=0
for i in range(n):
  a,b=f()
  for j in range(h+1):
    dp[j]=min(dp[j],dp[max(j-a,0)]+b)
print(dp[h])