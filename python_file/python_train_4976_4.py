import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    to = defaultdict(list)
    for _ in range(m):
        s, t = map(int, input().split())
        s, t = s - 1, t - 1
        to[s].append(t)
    ev = [0] * n
    for u in range(n - 2, -1, -1):
        s = 0
        for ku in to[u]:
            s += ev[ku]
        ev[u] = s / len(to[u]) + 1
    ans = ev[0]
    for nu in range(n - 1):
        if len(to[nu]) == 1: continue
        mx = 0
        mv = 0
        for nv in to[nu]:
            if ev[nv] > mx:
                mx = ev[nv]
                mv = nv
        for u in range(nu, -1, -1):
            s = 0
            for ku in to[u]:
                if (u, ku) == (nu, mv): continue
                s += ev[ku]
            od = len(to[u])
            if u == nu: od -= 1
            ev[u] = s / od + 1
        ans = min(ans, ev[0])
    print(ans)

main()
