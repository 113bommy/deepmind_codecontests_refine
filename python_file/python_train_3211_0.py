import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**15
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    n,z,w = LI()
    a = LI()
    m = {}
    def f(z,w,i,t):
        if i >= n:
            return abs(z-w)
        if t:
            k = (-1,w,i)
            if k in m:
                return m[k]
            r = -1
            for j in range(i,n):
                jr = f(a[j],w,j+1,False)
                if r < jr:
                    r = jr
            m[k] = r
        else:
            k = (z,-1,i)
            if k in m:
                return m[k]
            r = inf
            for j in range(i,n):
                jr = f(z,a[j],j+1,True)
                if r > jr:
                    r = jr
            m[k] = r
        return m[k]

    return f(z,w,-1,True)



print(main())


