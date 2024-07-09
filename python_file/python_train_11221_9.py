H,N=map(int,input().split())
dp=[10**12 for _ in range(H+1)]
dp[0]=0
for i in range(N):
  h,n=map(int,input().split())
  for j in range(H+1):
    dp[j]=min(dp[j],dp[max(0,j-h)]+n)
print(dp[H])