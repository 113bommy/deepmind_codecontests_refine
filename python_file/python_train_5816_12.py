from itertools import combinations
from heapq import heappush, heappop

class Dijkstra:
    def __init__(self, N):
        self.N = N # #vertices
        self.E = [[] for _ in range(N)]

    def add_edge(self, init, end, weight, undirected=False):
        self.E[init].append((end, weight))
        if undirected: self.E[end].append((init, weight))
    
    def distance(self, s):
        INF = float('inf')
        E, N = self.E, self.N
        self.dist = dist = [INF] * N # the distance of each vertex from s
        self.prev = prev = [-1] * N # the previous vertex of each vertex on a shortest path from s
        dist[s] = 0
        n_visited = 1 # #(visited vertices)
        heap = []
        heappush(heap, (0, s))
        while heap:
            d, v = heappop(heap)
            if dist[v] < d: continue
            for u, c in E[v]:
                temp = d + c
                if dist[u] > temp:
                    dist[u] = temp; prev[u] = v
                    heappush(heap, (temp, u))
            n_visited += 1
            if n_visited == N: break
        return dist
    
    def shortest_path(self, t):
        P = []
        prev = self.prev
        while True:
            P.append(t)
            t = prev[t]
            if t == -1: break
        return P[::-1]

def dist(p1, p2): return ((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2) ** 0.5
    
xs, ys, xt, yt = map(int, input().split())
N = int(input())
P = [[(xs, ys), 0, 0], [(xt, yt), 0, 1]]
for i in range(2, N+2):
    x, y, r = map(int, input().split())
    P.append([(x, y), r, i])
dk = Dijkstra(N+2)
for [p1, r1, i], [p2, r2, j] in combinations(P, 2):
    d = max(0, dist(p1, p2) - (r1 + r2))
    dk.add_edge(i, j, d, undirected=True)
print(dk.distance(0)[1])