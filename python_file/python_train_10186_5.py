from itertools import*
n,m,R=map(int,input().split())
r=map(int,input().split())
d=[[10**18]*n for _ in range(n)]
for i in range(m):
    a,b,c=map(int,input().split())
    d[a-1][b-1]=c
    d[b-1][a-1]=c
for i in range(n):
    d[i][i]=0
for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j]=min(d[i][j],d[i][k]+d[k][j])
m=10**18
for e in permutations(r):
    t=0
    for i,j in zip(e,e[1:]):
        t+=d[i-1][j-1]
    m=min(m,t)
print(m)