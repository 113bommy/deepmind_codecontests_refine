import sys
input = sys.stdin.buffer.readline
n,ma,mb=map(int,input().split())
ABC=[list(map(int,input().split())) for _ in range(n)]
infi=10**15
dp=[[[infi]*(401) for _ in range(401)]for _ in range(41)]
dp[0][0][0]=0
for i in range(n):
    a,b,c=ABC[i]
    for j in range(401-a):
        for k in range(401-b):
            ni=i+1
            nj=j+a
            nk=k+b
            dp[ni][j][k]=min(dp[ni][j][k], dp[i][j][k])
            dp[ni][nj][nk]=min(dp[i][j][k]+c,dp[ni][nj][nk])

ans=infi
for i in range(1,401):
    if ma*i>400:
        break
    if mb*i>400:
        break    
    ans=min(ans, dp[n][ma*i][mb*i])
print(ans if ans!=infi else -1)