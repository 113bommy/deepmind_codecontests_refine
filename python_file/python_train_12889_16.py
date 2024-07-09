N,W=map(int,input().split())
wv=[[0,0]]+[list(map(int,input().split()))for _ in range(N)]
v_max=sum(wv[i][1]for i in range(N+1))

dp=[[0]*(N+1)]+[[float('inf')]*(N+1)for _ in range(v_max)]
for v in range(1,v_max+1):
    for n in range(1,N+1):
        dp[v][n]=min((dp[v][n-1],dp[v-wv[n][1]][n-1]+wv[n][0]))

print(max(v for v in range(v_max+1) if dp[v][N]<=W))