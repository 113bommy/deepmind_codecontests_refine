import sys
input = sys.stdin.readline

from queue import *
N, M = map(int, input().split())
N *= 3
es = [[] for i in range(N)]
for i in range(M):
    u, v = map(lambda x : (int(x)-1)*3, input().split())
    es[u].append(v+1)
    es[u+1].append((v+2))
    es[u+2].append((v))
S, T = map(lambda x : (int(x)-1)*3, input().split())
dist = [-1 for i in range(N)]
dist[S] = 0
q = Queue()
q.put(S)
while not q.empty():
    v = q.get()
    for u in es[v]:
        if dist[u] == -1:
            dist[u] = dist[v] + 1
            q.put(u)
if dist[T] != -1:
    print(dist[T] // 3)
else:
    print(-1)