n=int(input())
l=sorted([(v,i+1) for i,v in enumerate(list(map(int,input().split())))],reverse=1)
dp=[[0]*(n+1) for i in range(n+1)]
for ko in range(1,n+1):
    for x in range(ko+1):
        ret=0
        v,i=l[ko-1]
        y=ko-x
        if y>=1:ret=max(ret,dp[x][y-1]+abs(n-y+1-i)*v)
        if x>=1:ret=max(ret,dp[x-1][y]+abs(x-i)*v)
        dp[x][y]=ret
print(max(dp[a][n-a] for a in range(n+1)))