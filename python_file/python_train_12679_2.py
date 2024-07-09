def WarshallFloyd(M):
    N = len(M)
    for k in range(N):
        for j in range(N):
            for i in range(N):
                M[i][j] = min(M[i][j], M[i][k] + M[k][j])
    return M

INF = float("inf")

N, M, L, *I = map(int, open(0).read().split())
ABC, ST = I[:3 * M], I[3 * M + 1:]

E = [[INF] * N for _ in range(N)]
for a, b, c in zip(*[iter(ABC)] * 3):
    E[a - 1][b - 1] = E[b - 1][a - 1] = c


E = WarshallFloyd(E)

for i in range(N):
    for j in range(N):
        if E[i][j] <= L:
            E[i][j] = 1
        else:
            E[i][j] = INF

E = WarshallFloyd(E)

for s, t in zip(*[iter(ST)] * 2):
    a = E[s - 1][t - 1] - 1
    print(-1 if a == INF else a)
