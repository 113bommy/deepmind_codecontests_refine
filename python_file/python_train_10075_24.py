n,s=map(int,input().split())
A=list(map(int,input().split()))
mod=998244353
ans=0
dp=[[0 for _ in range(s+1)] for _ in range(n+1)]
dp[0][0]=1

for i in range(n):
    for c in range(s+1):
        if c>=A[i]:
            dp[i+1][c]=(2*dp[i][c]+dp[i][c-A[i]])%mod
        else:
            dp[i+1][c]=(2*dp[i][c])%mod

print(dp[n][s]%mod)
