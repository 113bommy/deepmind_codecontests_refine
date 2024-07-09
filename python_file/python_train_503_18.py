n,a=map(int,input().split())
x=list(map(int,input().split()))
dp=[[[0 for _ in range(50*n+1)] for j in range(n+1)] for _ in range(n+1)] #dp[n][n][n*50]=cnt
dp[0][0][0] = 1
for i in range(1, n+1):
    for j in range(i+1):
        for k in range(50*n+1):
            if i > 0:
                dp[i][j][k] = dp[i-1][j][k]
                if k >= x[i-1]:
                    dp[i][j][k] += dp[i-1][j-1][k-x[i-1]]

ans = 0
for j in range(1,n+1):
    ans += dp[n][j][a*j]
print(ans)
