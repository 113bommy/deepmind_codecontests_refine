mod=10**9+7
N,M=map(int,input().split())
S=[int(i) for i in input().split()]
T=[int(i) for i in input().split()]
dp=[[0 for j in range(M)] for i in range(N)]
ans=[[0 for j in range(M+1)] for i in range(N+1)]
for i in range(N+1):
    ans[i][0]=1
for j in range(M+1):
    ans[0][j]=1
for i in range(N):
    for j in range(M):
        if S[i]==T[j]:
            dp[i][j]=ans[i][j]
        else:
            dp[i][j]=0
        ans[i+1][j+1]=dp[i][j]+ans[i+1][j]+ans[i][j+1]-ans[i][j]
        ans[i+1][j+1]%=mod
print(ans[N][M])
