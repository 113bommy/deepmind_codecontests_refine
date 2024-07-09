n,m,R=map(int,input().split())
r=[int(i) for i in input().split()]
inputs=[]
d=[[10**100 for i in range(n+1)] for i in range(n+1)]
for i in range(m):
    a,b,c=map(int,input().split())
    d[a][b]=c
    d[b][a]=c

def warshall_floyd(d):
    #d[i][j]: iからjへの最短距離
    for k in range(n+1):
        for i in range(n+1):
            for j in range(n+1):
                d[i][j] = min(d[i][j],d[i][k] + d[k][j])
    return d
d=warshall_floyd(d)
ans=10**100
import itertools
for x in itertools.permutations(r):
    p=0
    for i in range(1,R):
        p+=d[x[i-1]][x[i]]
    ans=min(ans,p)
print(ans)