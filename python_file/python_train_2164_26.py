from heapq import heappush, heappop

N, M, S = map(int, input().split())
mxCost = 0

edges = [[] for _ in range(N)]
for _ in range(M):
    fr, to, cost, dist = map(int, input().split())
    mxCost = max(mxCost, cost)
    fr -= 1
    to -= 1
    edges[fr].append((to, dist, cost))
    edges[to].append((fr, dist, cost))

for i in range(N):
    C, D = map(int, input().split())
    edges[i].append((i, D, -C))

que = [(0, S, 0)]
mxCost *= (N - 1)
minDsit = [[10**18] * (mxCost + 1) for _ in range(N)]
minDsit[0][0] = 0

while que:
    dist, s, now = heappop(que)

    for to, d, c in edges[now]:
        cost = min(mxCost, s - c)
        if cost < 0 or minDsit[to][cost] <= dist + d:
            continue
        minDsit[to][cost] = dist + d
        que.append((dist + d, cost, to))

for dist in minDsit[1:]:
    print(min(dist))
