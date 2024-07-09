import sys
sys.setrecursionlimit(10**6)

def dfs(v, u, k):
    for i in d[v]:
        if i[0] == u:
            continue
        kkyori[i[0]] = k + i[1]
        dfs(i[0], v, k + i[1])

N = int(input())
d = [[] for _ in range(N)]
for i in range(N - 1):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    d[a].append((b, c))
    d[b].append((a, c))
kkyori = [0] * N

Q, K = map(int, input().split())
dfs(K - 1, -1, 0)
for i in range(Q):
    x, y = map(int, input().split())
    print(kkyori[x - 1] + kkyori[y - 1])