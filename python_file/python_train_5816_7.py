xs, ys, xt, yt = map(int, input().split())
n = int(input())
p = [(xs, ys, 0), (xt, yt, 0)]
for i in range(n):
    p.append(tuple(map(int, input().split())))
edge = [[0] * (n + 2) for _ in range(n + 2)]
for i in range(n + 2):
    for j in range(i, n + 2):
        edge[i][j] = max(0, ((p[i][0] - p[j][0])**2 + (p[i][1] - p[j][1])**2)**0.5 - p[i][2] - p[j][2])
        edge[j][i] = max(0, ((p[i][0] - p[j][0])**2 + (p[i][1] - p[j][1])**2)**0.5 - p[i][2] - p[j][2])


def dijkstra(s, n, edges):
    INF = float('inf')
    d = [INF] * n
    d[s] = 0
    import heapq
    pq = [(0, s)]
    while len(pq):
        c, v = heapq.heappop(pq)
        if d[v] < c:
            continue
        # for v2nvcost, nv in edges[v]:
        for nv, v2nvcost in enumerate(edges[v]):
            if c + v2nvcost < d[nv]:
                d[nv] = c + v2nvcost
                heapq.heappush(pq, (d[nv], nv))
    return d


dist = dijkstra(0, n + 2, edge)
print(dist[1])
