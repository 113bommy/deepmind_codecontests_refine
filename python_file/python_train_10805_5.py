from collections import deque

N, *A = map(int, open(0).read().split())
V = N * (N - 1) // 2

serial = [[0 for _ in range(N)] for _ in range(N)]
k = 0
for i in range(N):
    for j in range(i + 1, N):
        serial[i][j] = serial[j][i] = k
        k += 1

G = [[] for _ in range(V)]
deg = [0] * V
for s, a in zip(serial, zip(*[iter(A)] * (N - 1))):
    for j in range(N - 2):
        G[s[a[j] - 1]].append(s[a[j + 1] - 1])
        deg[s[a[j + 1] - 1]] += 1

Q = deque((k, 1) for k, v in enumerate(deg) if v == 0)

ans = 0
cnt = len(Q)
while Q:
    v, ans = Q.popleft()
    for t in G[v]:
        deg[t] -= 1
        if deg[t] == 0:
            Q.append((t, ans + 1))
            cnt += 1

if cnt != V:
    print(-1)
else:
    print(ans)