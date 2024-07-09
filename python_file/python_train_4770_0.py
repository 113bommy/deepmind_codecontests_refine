import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    n,m = LI()
    if n == 1:
        return 1
    e = collections.defaultdict(list)
    for _ in range(n-1):
        a,b = LI_()
        e[a].append(b)
        e[b].append(a)

    rr = [None] * n

    fm = [None] * n
    def f(i,p):
        r = 1
        for c in e[i]:
            if c != p:
                r *= f(c,i) + 1
                r %= m
        fm[i] = r
        return r

    def g(i,p,pp):
        l = len(e[i])
        v = e[i]
        ta = [(pp if u==p else (fm[u] if not fm[u] is None else f(u,i))) + 1 for u in v]

        if l == 1:
            rr[i] = ta[0] % m
            return

        aa = [None] * l
        aa[0] = ta[0]
        for j in range(1,l):
            aa[j] = aa[j-1] * ta[j] % m

        ba = [None] * l
        ba[-1] = ta[-1]
        for j in range(l-2,-1,-1):
            ba[j] = ba[j+1] * ta[j] % m

        rr[i] = ba[0] % m
        if v[0] != p:
            g(v[0],i,ba[1])
        for j,u in enumerate(v[1:-1]):
            if u != p:
                g(u,i,aa[j]*ba[j+2]%m)
        if v[-1] != p:
            g(v[-1],i,aa[-2])

    def h(i):
        l = len(e[i])
        v = e[i]
        ta = [(fm[u] if not fm[u] is None else f(u,i)) + 1 for u in v]

        if l == 1:
            rr[i] = ta[0] % m
            g(v[0],i,1)
            return

        aa = [None] * l
        aa[0] = ta[0]
        for j in range(1,l):
            aa[j] = aa[j-1] * ta[j] % m

        ba = [None] * l
        ba[-1] = ta[-1]
        for j in range(l-2,-1,-1):
            ba[j] = ba[j+1] * ta[j] % m

        rr[i] = ba[0] % m
        g(v[0],i,ba[1])
        for j,u in enumerate(v[1:-1]):
            g(u,i,aa[j]*ba[j+2]%m)
        g(v[-1],i,aa[-2])

    h(1)


    return '\n'.join(map(str, rr))



print(main())


