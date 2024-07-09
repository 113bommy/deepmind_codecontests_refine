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
    n,k = LI()
    aa = [LS() for _ in range(n)]
    a = [[int(_[0]) + (k if _[2] == 'W' else 0), int(_[1])] for _ in aa]
    k2 = k*2
    aa = [[0] * k2 for _ in range(k2)]
    dr = [0, -2, -1, 0, 1, 2, 1, 0, -1, 2, 2, -2, -2]
    dc = [0, 0, 1, 2, 1, 0, -1, -2, -1, 2, -2, 2, -2]

    for x,y in a:
        x %= k2
        y %= k2
        for i in range(13):
            cx = x + dr[i] * k
            cy = y + dc[i] * k
            if cx >= k2 or cy >= k2 or cx <= -k or cy <= -k:
                continue
            mx = max(cx, 0)
            my = max(cy, 0)
            aa[mx][my] += 1
            if cx < k:
                aa[cx+k][my] -= 1
                if cy < k:
                    aa[cx+k][cy+k] += 1
            if cy < k:
                aa[mx][cy+k] -= 1

    for i in range(k2):
        for j in range(1,k2):
            aa[i][j] += aa[i][j-1]
    for i in range(k2):
        for j in range(1,k2):
            aa[j][i] += aa[j-1][i]
    return max(max(c) for c in aa)


print(main())


