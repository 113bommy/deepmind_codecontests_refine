n,m=map(int,input().split())
inf=10**12

ab=[]
cs=[]
for i in range(m):
    a,b=map(int,input().split())
    c=tuple(map(int,input().split()))
    ab.append((a,b))
    cs.append(c)
dp=[inf]*(2**n)
dp[0]=0
for i in range(m):
    x=0
    for h in cs[i]:
        x+=2**(h-1)
    for j in range(2**n):
        dp[j|x]=min(dp[j|x],dp[j]+ab[i][0])
print(dp[-1] if dp[-1]!=inf else -1)