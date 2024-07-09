import sys
import queue

input = sys.stdin.buffer.readline
INF = 10 ** 9

N = int(input())
path = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    path[a-1].append(b-1)
    path[b-1].append(a-1)

#find the longest path by trying BFS twice.
q = queue.Queue()
depth = [INF] * N
q.put(0)
depth[0] = 1
while not q.empty():
    node = q.get()
    for next_node in path[node]:
        if depth[next_node] > depth[node] + 1:
            depth[next_node] = depth[node] + 1
            q.put(next_node)

#The 'node' gives one end of the longest path.
q = queue.Queue()
depth = [INF] * N
q.put(node)
depth[node] = 1
while not q.empty():
    node = q.get()
    for next_node in path[node]:
        if depth[next_node] > depth[node] + 1:
            depth[next_node] = depth[node] + 1
            q.put(next_node)

length = depth[node]

if length % 3 == 2:
    print("Second")
else:
    print("First")