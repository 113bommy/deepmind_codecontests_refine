n,a=map(int,input().split())
x=list(map(int,input().split()))
p=min(a*n,sum(x))
dp=[[[0]*(n+1)for _ in range(p+1)]for _ in range(n+1)]
dp[0][0][0]=1
for i in range(1,n+1):
	for j in range(p+1):
		for k in range(n+1):
			dp[i][j][k]+=dp[i-1][j][k]
			if j-x[i-1]>=0 and k>=1:
				dp[i][j][k]+=dp[i-1][j-x[i-1]][k-1]
ans=0
for i in range(1,n+1):
	if i*a>p:
		break
	ans+=dp[-1][i*a][i]
print(ans)