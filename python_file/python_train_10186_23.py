from itertools import permutations

inf = float("inf")

N, M, R = map(int, input().split())
r = [int(s) - 1 for s in input().split()]
d = [[inf] * N for _ in range(N)]
for _ in range(M):
    a, b, c = map(int, input().split())
    d[a - 1][b - 1] = c
    d[b - 1][a - 1] = c
for k in range(N):
    for i in range(N):
        for j in range(N):
            d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j])
ans = min([sum([d[r[p[i]]][r[p[i+1]]] for i in range(R-1)])
           for p in permutations(range(R))])
print(ans)
