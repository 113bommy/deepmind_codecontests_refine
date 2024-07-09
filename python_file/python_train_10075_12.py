n,s = map(int,input().split())
A = list(map(int,input().split()))
mod = 998244353
dp = [[0 for i in range(s+1)] for j in range(n+1)]
dp[0][0] = 1
for i in range(n):
    for j in range(s+1):
        if j - A[i] >= 0:
            dp[i+1][j]=(dp[i][j]*2+dp[i][j-A[i]])%mod
        else:
            dp[i+1][j]=(dp[i][j]*2)%mod
print(dp[n][s])