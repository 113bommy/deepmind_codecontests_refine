from collections import defaultdict
import heapq

def dijkstra(G, s):
    q = []
    heapq.heapify(q)
    prev = [None] * len(G.keys())
    dist = [float('inf')] * len(G.keys())
    dist[s] = 0
    for v in sorted(G.keys()):
        heapq.heappush(q, (dist[v],v))
    while True:
        try:
            _, u = heapq.heappop(q)
        except:
            break
        for v, d in G[u]:
            tmp = dist[u] + d
            if dist[v] > tmp:
                dist[v] = tmp
                prev[v] = u
                heapq.heappush(q, (tmp, v))
    return dist

n, m, s, t = map(int, input().split())
G1 = defaultdict(list)
G2 = defaultdict(list)

for i in range(m):
    u, v, a, b = map(int, input().split())
    u -= 1
    v -= 1
    G1[u].append((v, a))
    G1[v].append((u, a))
    G2[u].append((v, b))
    G2[v].append((u, b))

dist1 = dijkstra(G1, s-1)
dist2 = dijkstra(G2, t-1)

mv = 0
ans = []
for i in range(n-1, -1, -1):
    mv = max(mv, 10**15 - dist1[i] - dist2[i])
    ans.append(mv)

ans.reverse()
for a in ans:
    print(a)