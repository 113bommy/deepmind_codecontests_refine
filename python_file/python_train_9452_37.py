N, M, P = map(int, input().split())
E = [None] * M
for i in range(M):
    a, b, c = map(int, input().split())
    E[i] = (a - 1, b - 1, P - c)
INF = float("inf")
d = [INF for _ in range(N)]
d[0] = 0
for i in range(2*N):
    for f, t, w in E:
        if d[t] > d[f] + w:
            d[t] = d[f] + w
            if i >= N:
                d[t] = -INF
    if i == N-1:
        dN = d[-1]
if dN != d[-1]:
    print(-1)
elif dN > 0:
    print(0)
else:
    print(-dN)
