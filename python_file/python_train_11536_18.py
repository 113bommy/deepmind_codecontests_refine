from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor
from functools import reduce


sys.setrecursionlimit(2147483647)
INF = float(10 ** 5)
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def I(): return int(sys.stdin.buffer.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().decode('utf-8').split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]
mod = 1000000007

n, m = LI()
G = [[] for _ in range(n)]
for _ in range(m):
    a, b = LI()
    G[a - 1] += [b - 1]
    G[b - 1] += [a - 1]

par = [-2] * n
par[0] = -1
used = set()
cnt = [0] * n

def dfs(u):
    for v in G[u]:
        if v in used or par[u] == v:
            continue
        if par[v] != -2:
            print(u + 1, v + 1)
            cnt[u] ^= 1
        else:
            par[v] = u
            if dfs(v):
                print(v + 1, u + 1)
                cnt[v] ^= 1
            else:
                print(u + 1, v + 1)
                cnt[u] ^= 1
    used.add(u)
    if cnt[u]:
        return 1

if m % 2:
    print(-1)
else:
    dfs(0)