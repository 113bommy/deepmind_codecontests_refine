from queue import Queue
import sys
N, M = map(int,input().split())
edges = [[] for _ in range(3 * N)]
flag = [0] * (3 * N)
for _ in range(M):
    u, v = map(int,input().split())
    u -= 1
    v -= 1
    edges[u % (3 * N)].append((v + N) % (3 * N))
    edges[(u + N) % (3 * N)].append((v + 2 * N) % (3 * N))
    edges[(u + 2 * N) % (3 * N)].append(v % (3 * N))

S, T = map(int,input().split())
q = Queue()
q.put([0,S-1])
while not q.empty():
    p = q.get()
    if p[1] == T-1:
        print(p[0] // 3)
        sys.exit()
    for i in edges[p[1]]:
        if flag[i] == 0:
            flag[i] = 1
            q.put([p[0]+1,i])
print(-1)