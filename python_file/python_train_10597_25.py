INF=float('inf')
n,m=map(int,input().split())
a=[0]*m
c=[0]*m
for i in range(m):
    a[i],_=map(int,input().split())
    c[i]=sum(map(lambda x:2**(int(x)-1),input().split()))
dp=[INF]*(2**n)
for i in range(m):
    for j in range(2**n):
        if j|c[i]==c[i]:
            dp[j]=min(dp[j],a[i])
        dp[c[i]|j]=min(dp[c[i]|j],dp[j]+a[i])
print(-1 if dp[-1]==INF else dp[-1])