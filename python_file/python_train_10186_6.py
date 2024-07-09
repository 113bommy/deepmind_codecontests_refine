n,m,r=map(int,input().split())
road=list(map(int,input().split()))
cost=[[float("inf")]*n for i in range(n)]
for i in range(n):
    cost[i][i]=0
for i in range(m):
    
    a,b,c=map(int,input().split())
    a,b=a-1,b-1
    cost[a][b]=c
    cost[b][a]=c
for k in range(n):
    for i in range(n):
        for j in range(n):
            cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j])
import itertools
ans=float("inf")
for i in itertools.permutations(road):
    tmp=0
    for j in range(len(i)-1):
        tmp+=cost[i[j]-1][i[j+1]-1]
    if tmp<ans:
        ans=tmp
print(ans)