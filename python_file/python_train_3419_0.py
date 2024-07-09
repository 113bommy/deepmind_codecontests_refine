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


def main():
    h,w,d = LI()
    r = [['.']*w for _ in range(h)]
    cs = ['R','Y','G','B']
    for i in range(0,h+d,d):
        for j in range(0,w+d,d):
            c = cs[(i+j) % (d*2) // d]
            for ii in range(-d,d):
                for jj in range(-d,d):
                    if i+ii < 0 or i+ii >= h or j+jj < 0 or j+jj >= w or abs(ii)+abs(jj) >= d or abs(ii)+abs(d-jj-1) >= d:
                        continue
                    r[i+ii][j+jj] = c
    for i in range(1,h+d,d):
        for j in range(0,w+d,d):
            c = cs[(i+j) % (d*2) // d + 2]
            for ii in range(d):
                for jj in range(d):
                    if i+ii < 0 or i+ii >= h or j+jj < 0 or j+jj >= w:
                        continue
                    if abs(ii)+abs(jj) >= d or r[i+ii][j+jj] != '.' or jj > ii:
                        break
                    r[i+ii][j+jj] = c
                for jj in range(-1,-d-1,-1):
                    if i+ii < 0 or i+ii >= h or j+jj < 0 or j+jj >= w:
                        continue
                    if abs(ii)+abs(jj) >= d or r[i+ii][j+jj] != '.':
                        break
                    r[i+ii][j+jj] = c


    return '\n'.join([''.join(c) for c in r])


print(main())


