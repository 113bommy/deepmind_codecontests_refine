N,*M = map(int,input().split())
abc = [list(map(int,input().split())) for _ in [0]*N]
INF = 100*40*100
dp = [[[INF]*500 for _ in [0]*500] for _ in [0]*(N+1)]
dp[0][0][0] = 0
for i in range(1,N+1):
    a,b,c = abc[i-1]
    for j in range(410):
        for k in range(410):
            dp[i][j][k] = min(dp[i-1][j][k],dp[i-1][j-a][k-b]+c)
ans = min([dp[-1][M[0]*i][M[1]*i] for i in range(1,1+400//(max(M)))])
if ans == INF:ans=-1
print(ans)