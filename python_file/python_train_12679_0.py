n, m, l = map(int, input().split())

INF = 1 << 30
g = [[INF] * n for _ in range(n)]
for _ in range(m):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    g[a][b] = c
    g[b][a] = c

for k in range(n):
    for i in range(n):
        for j in range(n):
            g[i][j] = min(g[i][j], g[i][k] + g[k][j])

h = [[INF] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if g[i][j] <= l:
            h[i][j] = 1

for k in range(n):
    for i in range(n):
        for j in range(n):
            h[i][j] = min(h[i][j], h[i][k] + h[k][j])

q = int(input())
for _ in range(q):
    s, t = map(lambda x: int(x) - 1, input().split())
    if h[s][t] == INF:
        print(-1)
    else:
        print(h[s][t] - 1)
