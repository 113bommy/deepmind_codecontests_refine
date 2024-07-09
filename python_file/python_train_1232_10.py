import sys
sys.setrecursionlimit(100000000)
def dfs(cur,par,d):
    dist[cur]=d
    for nx,nx_dist in G[cur]:
        if nx==par:continue
        dfs(nx,cur,d+nx_dist)

n=int(input())
G=[[] for i in range(n)]
dist=[0]*n
for i in range(n-1):
    a,b,c=map(int,input().split())
    G[a-1].append([b-1,c])
    G[b-1].append([a-1,c])
q,k=map(int,input().split())
k-=1
dfs(k,-1,0)
for i in range(q):
    x,y=map(int,input().split())
    x-=1
    y-=1
    print(dist[x]+dist[y])