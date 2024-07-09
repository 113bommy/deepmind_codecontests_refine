def flpl(): return [float(i) for i in input().split()]
def inpl(): return [int(i) for i in input().split()]
import heapq
def dijkstra(vnum, vs):
    dist = [float('inf') for _ in range(vnum)]
    dist[vs] = 0 
    remain = set(range(vnum))
    Q = []
    heapq.heappush(Q,(0,vs))
    while Q:
        c, vn = heapq.heappop(Q)
        if vn not in remain :
            continue
        remain.remove(vn)
        for j in remain:
            evnj = edge(vn, j)
            if dist[vn] + evnj < dist[j]:
                dist[j] = dist[vn] + evnj 
                heapq.heappush(Q,(dist[j],j)) 
        if not remain:
            break
    return dist
def edge(s, t):
    return max(((X[s] - X[t])**2 + (Y[s] - Y[t])**2)**(1/2) -(R[s]+R[t]), 0)

xs, ys, xt, yt = flpl()
N = int(input())
xyr = [(xs, ys, 0),(xt, yt, 0)] + [inpl() for _ in range(N)]
X, Y, R = list(map(list, zip(*xyr)))
D = dijkstra(N+2, 0)
print(D[1])