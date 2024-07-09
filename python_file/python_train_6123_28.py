N = int(input())
edge = [[] for _ in range(N)]
for i in range(N-1):
    a,b = map(int, input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)

import sys
sys.setrecursionlimit(10**8)

mod = 10**9+7
def dfs(v):
    white,black = 1,1
    for u in edge[v]:
        if visited[u]==False:
            visited[u]=True
            w,b = dfs(u)
            white *= w+b
            white %= mod
            black *= w
            black %= mod
    return white,black

visited = [False]*N
visited[0]=True
print(sum(dfs(0))%mod)