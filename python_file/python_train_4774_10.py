I=lambda:list(map(int,input().split()))
n,Ma,Mb=I()
m=[[0,0,0]]+[I()for _ in range(n)]
dp=[[[10**18]*(10*n+1)for _ in range(10*n+1)]for _ in range(n+1)]
dp[0][0][0]=0
for i in range(1,n+1):
    for j in range(10*n+1):
        if j-m[i][0]<0:
            dp[i][j]=dp[i-1][j]
            continue
        for k in range(10*n+1):
            if k-m[i][1]<0:
                dp[i][j][k]=dp[i-1][j][k]
            else:
                dp[i][j][k]=min(dp[i-1][j-m[i][0]][k-m[i][1]]+m[i][2],dp[i-1][j][k])
ans=10**18
for i in range(1,10*n+1):
    j=Mb*i/Ma
    if j==int(j) and j<10*n+2:
        ans=min(ans,dp[-1][i][int(j)])
print(-(ans==10**18)or ans)