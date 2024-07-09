from collections import deque

N, Q = map(int, input().split())
V = [0] * N
E = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    E[a-1].append(b-1)
for _ in range(Q):
    p, x = map(int, input().split())
    V[p-1] += x

stack = deque()
stack.append(0)
ans = [0] * N
ans = V

while stack:
    v = stack.popleft()
    for e in E[v]:
        ans[e] += ans[v]
        stack.append(e)

print(*ans)

