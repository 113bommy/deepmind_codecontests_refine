# -*- coding: utf-8 -*-
from itertools import permutations, product
def inpl(): return tuple(map(int, input().split()))
N, M, R = inpl()
inf = float("inf")
G = [[inf for _ in range(N+1)] for _ in range(N+1)]
D = inpl() # destination

for _ in range(M):
    a, b, c = inpl()
    G[a][b] = c
    G[b][a] = c

for n in range(N+1):
    G[n][n] = 0

for i ,j, k in product(range(1, N+1), repeat=3):
    G[j][k] = min(G[j][k], G[j][i] + G[i][k])

res = inf
for C in permutations(D, len(D)):
    res = min(res, sum([G[C[i]][C[i+1]] for i in range(len(D)-1)]))

print(res)