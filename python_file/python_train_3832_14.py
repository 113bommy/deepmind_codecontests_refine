N, = map(int, input().split())
import sys
sys.setrecursionlimit(10**6)
d = [set() for _ in range(N+1)]
Cs = [0 for _ in range(N+1)]
for _ in range(N-1):
    u, v, p = map(int, input().split())
    d[u].add((v, p))
    d[v].add((u, p))

def it(v, p):
    for u, c in d[v]:
        if u == p:
            continue
        Cs[u] = int(not Cs[v]) if c%2 else Cs[v]
        it(u, v)
it(1, None)
for i in range(1, N+1):
    print(Cs[i])
