from collections import deque

N, K = map(int, input().split())
T = [[] for i in range(N)]
E = []
for i in range(N-1):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    T[a].append(b)
    T[b].append(a)
    E.append([a, b])


def bfs(n):
    visited = [False] * N
    dist = [0] * N
    queue = deque([n])
    while queue:
        node = queue.pop()
        if visited[node]:
            continue
        visited[node] = True
        for n in T[node]:
            if not visited[n]:
                dist[n] = dist[node] + 1
                queue.appendleft(n)
    return dist


dist = []
for i in range(N):
    dist.append(bfs(i))

ans = float('inf')
if K % 2 == 0:
    for i in range(N):
        ans = min(ans, len([d for d in dist[i] if d > K / 2]))

else:
    for a, b in E:
        ans = min(ans, len([d for d in [min(d1, d2) for d1, d2 in zip(dist[a], dist[b])] if d> (K-1) / 2]))

print(ans)
