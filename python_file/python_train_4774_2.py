
n,a,b = map(int,input().split())
l = [list(map(int,input().split())) for i in range(n)]
INF = 500
dp = [[[INF for i in range(411)] for j in range(411)] for k in range(n+1)]
dp[0][0][0] = 0
for i in range(n):
    for j in range(a*n+1):
        for k in range(b*n+1):
            if j - l[i][0]>=0 and k - l[i][1]>=0:
                dp[i+1][j][k] = min(dp[i][j][k],dp[i][j - l[i][0]][k - l[i][1]]+l[i][2])
            else:
                dp[i+1][j][k] = dp[i][j][k]
i =1
ans = INF
while i*max(a,b)<=400:
    ans = min(ans, dp[n][i*a][i*b])
    i+=1
if ans==INF:
    print(-1)
else:
    print(ans)