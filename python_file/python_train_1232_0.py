import sys
sys.setrecursionlimit(10**7)
N = int(input())
G = [[] for _ in range(N+1)]
for _ in range(N-1):
    a, b, c = map(int, input().split())
    G[a].append((b, c))
    G[b].append((a, c))
Q, K = map(int, input().split())


d = [-1]*(N+1)


def dfs(v, c):
    d[v] = c
    for nv, cost in G[v]:
        if d[nv] == -1:
            dfs(nv, cost+c)

dfs(K, 0)

for _ in range(Q):
    x, y = map(int, input().split())
    print(d[x]+d[y])
