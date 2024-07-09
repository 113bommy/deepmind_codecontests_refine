
n, m = list(map(int, input().split()))
edges = [[] for i in range(n)]
for i in range(m):
    tx, ty, _tz = list(map(int, input().split()))
    edges[tx-1].append(ty-1) 
    edges[ty-1].append(tx-1) 
visited = [False] * n
ans = 0
for i in range(n):
    if not visited[i]:
        q = [i]
        visited[i] = True
        while q:
            u = q.pop(0)
            for v in edges[u]:
                if not visited[v]:
                    q.append(v)
                    visited[v] = True
        ans += 1
print(ans)
