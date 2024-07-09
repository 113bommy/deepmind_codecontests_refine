import sys
sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline

mod = 10**9+7
n = int(input())
g = [[] for _ in range(n)]

for _ in range(n-1):
    x, y = map(int, input().split())
    g[x-1].append(y-1)
    g[y-1].append(x-1)

white = [0 for _ in range(n)]
black = [0 for _ in range(n)]


def dfs(v):
    tmp_w = 1
    tmp_b = 1
    if len(g[v]) == 0:
        white[v] = 1
        black[v] = 1
        return None
    for w in g[v]:
        g[w].remove(v)
        dfs(w)
        tmp_w *= white[w]+black[w]
        tmp_b *= white[w]
        tmp_w %= mod
        tmp_b %= mod
    white[v] = tmp_w
    black[v] = tmp_b
    return None


dfs(0)

print((white[0]+black[0]) % mod)
