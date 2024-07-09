import itertools

n,m,R=map(int,input().split())
r=list(map(int,input().split()))
INF = 10**10
d=[[INF for i in range(n)] for i in range(n)]

for i in range(m):
    a,b,c=map(int,input().split())
    d[a-1][b-1]=c
    d[b-1][a-1]=c

for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j] ,d[i][k] +d[k][j])

for i in range(R):
    r[i] -= 1

res = INF
for rp in itertools.permutations(r):
    tres = 0
    for i in range(R-1):
        tres += d[rp[i]][rp[i+1]]
    res = min(res,tres)

print(res)