from heapq import heappush, heappop
K = int(input())
INF = float("inf")
d = [INF] * K
G = [[] for i in range(K)]
for i in range(K):
    G[i].append(((i + 1) % K, 1))
    G[i].append(((10 * i) % K, 0))

d[1] = 0
que = [(1, 0)]
while que:
    v, cost = heappop(que)
    if d[v] < cost:
        continue

    for w, c in G[v]:
        if d[w] > d[v] + c:
            d[w] = d[v] + c
            heappush(que, (w, d[w]))

print(d[0] + 1)
