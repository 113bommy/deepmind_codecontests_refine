n,s=map(int,input().split())
a=list(map(int,input().split()))
t=[[0]*(s+1) for i in range(n+1)]
t[0][0]=1
m=998244353
for i in range(n):
    for j in range(s+1):
        t[i+1][j]=t[i][j]*2
        if j>=a[i]:
            t[i+1][j]+=t[i][j-a[i]]
        t[i+1][j]%=m
print(t[-1][-1])