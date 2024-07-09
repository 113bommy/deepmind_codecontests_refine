A,B,C,D=map(int,input().split())
mod=998244353
dp=[[0 for y in range(D-B+1)]for x in range(C-A+1)]
dp[0][0]=1
for x in range(C-A):
    dp[x+1][0]=(dp[x][0]*B)%mod
for y in range(D-B):
    dp[0][y+1]=(dp[0][y]*A)%mod
for x in range(C-A):
    for y in range(D-B):
        dp[x+1][y+1]=(dp[x+1][y]*(A+x))%mod
        dp[x+1][y+1]+=(dp[x][y+1]*(B+y))%mod
        dp[x+1][y+1]%=mod
        dp[x+1][y+1]-=(dp[x][y]*(A+x)*(B+y))%mod
        dp[x+1][y+1]%=mod
        dp[x+1][y+1]+=(dp[x+1][y]+dp[x][y+1])%mod
        dp[x+1][y+1]%=mod

print(dp[C-A][D-B])
