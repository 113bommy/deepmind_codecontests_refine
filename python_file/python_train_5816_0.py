#!usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def LS():return [list(x) for x in sys.stdin.readline().split()]
def S():
    res = list(sys.stdin.readline())
    if res[-1] == "\n":
        return res[:-1]
    return res

def IR(n):
    return [I() for i in range(n)]
def LIR(n):
    return [LI() for i in range(n)]
def SR(n):
    return [S() for i in range(n)]
def LSR(n):
    return [LS() for i in range(n)]

sys.setrecursionlimit(1000000)
mod = 1000000007

#A
def A():
    n = I()

    return

#B
def B():
    n = I()

    return

#C
def C():
    def dist(a,b):
        xa,ya,ra = a
        xb,yb,rb = b
        return max(0, ((xa-xb)**2+(ya-yb)**2)**0.5-(ra+rb))

    xs,ys,xt,yt = LI()
    n = I()
    p = LIR(n)
    v = [[] for i in range(n+2)]
    a = (xs,ys,0)
    b = (xt,yt,0)
    d = dist(a,b)
    v[0].append((n+1, d))
    for i in range(n):
        d = dist(a,p[i])
        v[0].append((i+1,d))
        d = dist(p[i],b)
        v[i+1].append((n+1,d))
        for j in range(i+1,n):
            d = dist(p[i],p[j])
            v[i+1].append((j+1,d))
            v[j+1].append((i+1,d))
    d = [float("inf")]*(n+2)
    q = [(0,0)]
    d[0] = 0
    while q:
        dx,x = heappop(q)
        if x > n:
            print(d[x])
            return
        if d[x] < dx:
            continue
        for y,w in v[x]:
            nd = dx+w
            if nd < d[y]:
                d[y] = nd
                heappush(q,(nd,y))
    return

#D
def D():
    n = I()

    return

#E
def E():
    n = I()

    return

#F
def F():
    n = I()

    return

#Solve
if __name__ == "__main__":
    C()
