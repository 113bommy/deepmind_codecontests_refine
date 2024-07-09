n,k=map(int,input().split())
h=list(map(int,input().split()))
dp=[10**9+5]*n
dp[0]=0
dp[1]=abs(h[0]-h[1])
for i in range(2,n):
    for j in range(max(0,i-k),i):
        dp[i]=min(dp[i],dp[j]+abs(h[i]-h[j]))
print(dp[-1])