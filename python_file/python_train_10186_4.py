n,m,R=map(int,input().split())
r=list(map(int,input().split()))

d=[[float("INF")]*n for i in range(n)]
for i in range(n):
  d[i][i]=0

for i in range(m):
  a,b,c=map(int,input().split())
  d[a-1][b-1]=c
  d[b-1][a-1]=c
  
#ワーシャルフロイド法
#d[i][j]:iからjへの最短経路
for k in range(n):
  for i in range(n):
    for j in range(n):
      d[i][j]=min(d[i][j],d[i][k]+d[k][j])

      
from itertools import permutations
per=list(permutations(r,R))

ans=float("INF")
for l in per:
  cnt=0
  for j in range(R-1):
    cnt+=d[l[j]-1][l[j+1]-1]
  ans=min(cnt,ans)
print(ans)

      
      
  
