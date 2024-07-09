n=int(input())
a=list(map(int,input().split()))
flag=[[0 for j in range(n)] for i in range(n)]
dp=[[0 for j in range(n)] for i in range(n)]
ru=[0]
for i in range(n):
    ru.append(ru[-1]+a[i])
def f(l,r):
    if flag[l][r]==1:
        return dp[l][r]
    flag[l][r]=1
    if l==r:
        return 0
    fans=10**20
    for m in range(l,r):
        fans=min(fans,f(l,m)+f(m+1,r))
    dp[l][r]=fans+ru[r+1]-ru[l]
    return dp[l][r]

ans=f(0,n-1)
print(ans)