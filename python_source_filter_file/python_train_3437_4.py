V=int(input())

G=[[] for i in range(V)]
d=[1001001001 for i in range(V)]

import heapq

def dijkstra(s):
    q=[]
    d[s]=0
    heapq.heappush(q,(0, s))
    
    while(len(q)):
        print(q)
        p=heapq.heappop(q)
        v=p[1]
        if d[v]<p[0]:
            continue
        for e in G[v]:
            if d[e[0]]>d[v]+e[1]:
                d[e[0]]=d[v]+e[1]
                
                heapq.heappush(q, (d[e[0]], e[0]))

import sys
for l in sys.stdin:
    l=list(map(int,l.split()))
    u=l[0]
    k=l[1]
    G[u]=zip(*[iter(l[2:])]*2)
    
dijkstra(0)
for i in range(V):
    print(i, d[i])
    

    