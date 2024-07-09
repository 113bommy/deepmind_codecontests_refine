import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools
# import time,random,resource

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
mod2 = 998244353
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(): return [list(map(int, l.split())) for l in sys.stdin.readlines()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)
def pe(s): return print(str(s), file=sys.stderr)
def JA(a, sep): return sep.join(map(str, a))
def JAA(a, s, t): return s.join(t.join(map(str, b)) for b in a)
def IF(c, t, f): return t if c else f

def scc(n, e, re):
    v = [None] * n
    t = []
    def dfs(i):
        v[i] = 0
        for b in e[i]:
            if v[b] is None:
                dfs(b)
        t.append(i)

    for i in range(n):
        if v[i] is None:
            dfs(i)

    r = [None] * n
    def dfs2(i, p):
        r[i] = p
        for b in re[i]:
            if r[b] is None:
                dfs2(b, p)

    for c in t[::-1]:
        if r[c] is None:
            dfs2(c, c)

    return r


def main():
    n,m = LI()
    ab = [LI() for _ in range(m)]

    e = collections.defaultdict(set)
    re = collections.defaultdict(set)
    for a,b in ab:
        e[a].add(b)
        re[b].add(a)

    sc = scc(n,e,re)
    d = {}
    ci = collections.defaultdict(list)
    for i,c in enumerate(sc):
        ci[c].append(i)
        d[i] = c

    cs = list(ci.keys())
    se = collections.defaultdict(set)
    sre = collections.defaultdict(set)
    for a,b in ab:
        if d[a] == d[b]:
            continue
        se[d[a]].add(d[b])
        sre[d[b]].add(d[a])

    rr = []
    q = []
    for c in cs:
        if len(sre[c]) == 0:
            q.append(c)

    qi = 0
    while qi < len(q):
        c = q[qi]
        qi += 1
        rr.append(JA([len(ci[c])] + ci[c], " "))
        for nc in se[c]:
            sre[nc].remove(c)
            if len(sre[nc]) == 0:
                q.append(nc)

    return JA([len(rr)] + rr, "\n")


print(main())


