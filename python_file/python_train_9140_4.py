N=int(input())
p=list(map(float,input().split()))
dp=[[0 for _ in range(N+1)] for _ in range(N+1)]
dp[0][0]=1
for i in range(N):
    for j in range(N):
        dp[i+1][j]+=dp[i][j]*(1-p[i])
        dp[i+1][j+1]+=dp[i][j]*p[i]
print(sum(dp[-1][N//2+1:]))