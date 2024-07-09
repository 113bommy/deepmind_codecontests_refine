n,m,s=map(int,input().split())
s=min(s,2500)
edge=[[] for i in range(n*50*51)]
for i in range(m):
    u,v,a,b=map(int,input().split())
    for j in range(a,2501):
        edge[u-1+j*n].append((v-1+(j-a)*n,b))
        edge[v-1+j*n].append((u-1+(j-a)*n,b))
for i in range(n):
    c,d=map(int,input().split())
    for j in range(2501-c):
        edge[i+j*n].append((i+(j+c)*n,d))
    for j in range(2500):
        edge[i+(j+1)*n].append((i+j*n,0))
from heapq import heappush,heappop,heapify
d = [float('inf') for i in range(n*50*51)]
pq = []
heappush(pq,(0,s*n))
while pq:
    weight,u = heappop(pq)
    if d[u]>weight:
        d[u]=weight
        for v,weight in edge[u]:
            heappush(pq,(d[u]+weight,v))
for i in range(1,n):
    print(d[i])