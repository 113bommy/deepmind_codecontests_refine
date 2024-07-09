import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

N = int(input())
G = [[] for _ in range(N)]
for _ in range(N-1):
    x, y = map(lambda x: int(x) - 1, input().split())
    G[x].append(y)
    G[y].append(x)

nim = [0] * N

def dfs(v, p):
    for c in G[v]:
        if c != p:
            dfs(c, v)
            nim[v] ^= nim[c]
    nim[v] += 1

dfs(0, -1)
print('Alice' if nim[0] > 1 else 'Bob')