# -*- coding: utf-8 -*-

import sys
import time

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

n, p, w, d = MAP()

mxx = p // w
y = -1
start = time.time()
for x in range(mxx, -1, -1):
    if (p-w*x) % d == 0:
        y = (p-w*x) // d
        break
    elapsed_time = time.time() - start
    if elapsed_time > 0.7:
        print(-1)
        exit()

if y == -1:
    print(-1)
    exit()
z = n - x - y
if z < 0:
    print(-1)
    exit()

print(x, y, z)
