MOD=1000000007
n,m=map(int,input().split())

S=[int(_) for _ in input().split()]
T=[int(_) for _ in input().split()]

dp=[[0 for j in range(m+1)] for i in range(n+1)]
for i in range(n+1):
  dp[i][0]=1
for j in range(m+1):
  dp[0][j]=1

for i in range(n):
    for j in range(m):
        if S[i]!=T[j]:
            dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]-dp[i][j]
            dp[i+1][j+1]%=MOD
        else:
            dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]
            dp[i+1][j+1]%=MOD
print((dp[n][m])%MOD)