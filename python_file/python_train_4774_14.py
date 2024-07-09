N,Ma,Mb=map(int,input().split())
a,b,c=map(list,zip(*[list(map(int,input().split())) for i in range(N)]))
ma,mb=sum(a),sum(b)
MAX=5000
dp=[[[MAX]*(mb+1) for i in range(ma+1)] for j in range(N+1)]
dp[0][0][0]=0
for i in range(N):
    for j in range(ma):
        for k in range(mb):
            dp[i+1][j][k]=min(dp[i][j][k],dp[i+1][j][k])
            if j+a[i]<=ma and k+b[i]<=mb:
                dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i])
ans=MAX
x=1
while x*Ma<=ma and x*Mb<=mb:
    ans=min(ans,dp[N][x*Ma][x*Mb])
    x+=1
print(ans if ans<MAX else -1)