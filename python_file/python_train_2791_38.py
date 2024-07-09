n,k=map(int,input().split())
c=list(map(int,input().split()))
dp=[0]*n
dp[0]=0
for i in range(1,n):
    dp[i]=min([dp[j]+abs(c[i]-c[j]) for j in range(max(0,i-k),i)])
print(dp[-1])