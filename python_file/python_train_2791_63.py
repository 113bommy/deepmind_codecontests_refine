n,k=map(int,input().split())
dp=[10**4*n]*n
l=list(map(int,input().split()))
dp[0]=0
for i in range(1,n):
  dp[i]=min(dp[i-j]+abs(l[i-j]-l[i]) for j in range(1,min(i,k)+1))
print(dp[-1])