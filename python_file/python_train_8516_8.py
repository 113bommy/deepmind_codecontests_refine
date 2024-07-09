import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**13
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
    n = I()
    s = S()
    sa = []
    for c in s:
        if c == 'D':
            sa.append(1)
        elif c == 'M':
            sa.append(2)
        elif c == 'C':
            sa.append(3)
        else:
            sa.append(None)
    q = I()
    kk = LI()
    rr = []
    for k in kk:
        a = 0
        b = 0
        t = 0
        r = 0
        for j in range(k):
            if sa[j] is None:
                continue
            if sa[j] == 3:
                r += t
            elif sa[j] == 2:
                t += a
                b += 1
            else:
                a += 1
        for j in range(k,n):
            if sa[j-k] == 1:
                t -= b
                a -= 1
            elif sa[j-k] == 2:
                b -= 1

            if sa[j] is None:
                continue
            if sa[j] == 3:
                r += t
            elif sa[j] == 2:
                t += a
                b += 1
            else:
                a += 1

        rr.append(r)

    return '\n'.join(map(str, rr))


print(main())
