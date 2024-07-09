n=int(input())
a=list(map(int,input().split()))
dp=[[0]*n for i in range(n)]
for i in range(n):
    if n%2==0:
        dp[i][i]=-a[i]
    else:
        dp[i][i]=a[i]
for l in range(1,n):
    if n%2==l%2:
        for right in range(l,n):
            left=right-l
            dp[left][right]=min(dp[left+1][right]-a[left],dp[left][right-1]-a[right])
    else:
        for right in range(l,n):
            left=right-l
            dp[left][right]=max(dp[left+1][right]+a[left],dp[left][right-1]+a[right])
print(dp[0][n-1])