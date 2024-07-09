import sys
input=sys.stdin.readline
inf=10**9+7
n,m,l=map(int,input().split())
D=[[inf]*(n+1) for _ in range(n+1)]
for _ in range(m):
    a,b,c=map(int,input().split())
    D[a][b]=c
    D[b][a]=c

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            D[i][j]=min(D[i][j],D[i][k]+D[k][j])

DD=[[inf]*(n+1) for _ in range(n+1)]
for x in range(1,n+1):
    for y in range(1,n+1):
        if D[x][y]<=l:
            DD[x][y]=1

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            DD[i][j]=min(DD[i][j],DD[i][k]+DD[k][j])

q=int(input())
for _ in range(q):
    s,t=map(int,input().split())
    if DD[s][t]==inf:
        print(-1)
    else:
        print(DD[s][t]-1)