import itertools
n,m,r=map(int,input().split())
rr=list(map(int,input().split()))
inf=10000000000
g=[[inf for i in range(n)] for j in range(n)]
for i in range(m):
    a,b,c=map(int,input().split())
    g[a-1][b-1]=c
    g[b-1][a-1]=c
for k in range(n):
    for i in range(n):
        for j in range(n):
            g[i][j]=min(g[i][j],g[i][k]+g[k][j])


ans=10**10
for i in itertools.permutations(range(0,r),r):
    kai=0
    for j in range(r-1):
        kai+=g[rr[i[j]]-1][rr[i[j+1]]-1]
    ans=min(ans,kai)
print(ans)