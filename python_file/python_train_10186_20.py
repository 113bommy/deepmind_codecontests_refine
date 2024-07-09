import itertools, math

N, M, R = map(int, input().split())
r = list(map(int, input().split()))

adj = [[float('inf')] * (N + 1) for _ in range(N + 1)]

for m in range(M):
    A, B, C = map(int, input().split())
    adj[A][B] = min(adj[A][B], C)
    adj[B][A] = min(adj[B][A], C)

res = float('inf')

for k in range(1, N + 1):
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])

for perm in itertools.permutations(r):
    best = 0
    for x, y in zip(perm, perm[1:]):
        best += adj[x][y]
    res = min(res, best)

print(res)