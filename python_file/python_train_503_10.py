def makelist(n,m,p):
    return [[[0 for k in range(p)]for i in range(m)]for j in range(n)]

n,a = map(int,input().split())
x = list(map(int,input().split()))
X = max(x)
X = max(X,a)

dp = makelist(n+1,n+1,n*X+1)
dp[0][0][0] = 1
for j in range(n+1):
    for k in range(n+1):
        for s in range(n*X+1):
            if j*k > 0 and s >= x[j-1]:
                dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j-1]]
            elif j >= 1 and s < x[j-1]:
                dp[j][k][s] = dp[j-1][k][s]
ans = 0
for k in range(1,n+1):
    ans += dp[n][k][k*a]
print(ans)