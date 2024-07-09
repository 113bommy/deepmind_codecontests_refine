N,M,S=map(int,input().split())
UVAB=[list(map(int,input().split())) for i in range(M)]
C,D=zip(*[list(map(int,input().split())) for i in range(N)])
c=[[] for i in range(N)]
A=[[] for i in range(N)]
B=[[] for i in range(N)]
for u,v,a,b in UVAB:
    c[u-1].append(v-1)
    c[v-1].append(u-1)
    A[u-1].append(a)
    A[v-1].append(a)
    B[u-1].append(b)
    B[v-1].append(b)
inf=10**20
from heapq import heappop,heappush
X=50*(N-1)
def dij(p,s):
    d=[[inf]*(X+1) for i in range(N)]
    d[p][s]=0
    q=[]
    heappush(q,(0,(p,s)))
    while q:
        t,(p,s)=heappop(q)
        for i in range(1,(X+1-s)//C[p]):
            if X<s+i*C[p] or d[p][s+i*C[p]]<=d[p][s]+i*D[p]:break
            d[p][s+i*C[p]]=d[p][s]+i*D[p]
            heappush(q,(d[p][s]+i*D[p],(p,s+i*C[p])))
        for j,n in enumerate(c[p]):
            if 0<=s-A[p][j] and d[n][s-A[p][j]]>d[p][s]+B[p][j]:
                d[n][s-A[p][j]]=d[p][s]+B[p][j]
                heappush(q,(d[n][s-A[p][j]],(n,s-A[p][j])))
    return d
d=dij(0,min(S,X))
print(*[min(x) for x in d[1:]],sep='\n')