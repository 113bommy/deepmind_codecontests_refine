import sys
sys.setrecursionlimit(10 ** 7)

N = int(input())
T, D = {i: [] for i in range(N)}, [-1] * N
for _ in range(N - 1):
    a, b, c = map(int, input().split())
    T[a - 1].append((b - 1, c))
    T[b - 1].append((a - 1, c))


def dfs(p, c, d):
    D[c] = d
    for c2, d2 in T[c]:
        if c2 != p:
            dfs(c, c2, d + d2)


Q, K = map(int, input().split())
dfs(-1, K - 1, 0)
for _ in range(Q):
    x, y = map(int, input().split())
    print(D[x - 1] + D[y - 1])
