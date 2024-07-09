h,n=map(int,input().split())
l=[list(map(int,input().split())) for _ in range(n)]
dp=[10**9]*(h+max(l)[0])
dp[0]=0
for i in range(1,len(dp)):
  for a,b in l:
    if i-a>=0:
      dp[i]=min(dp[i],dp[i-a]+b)
print(min(dp[h:]))