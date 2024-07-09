from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from bisect import bisect_right, bisect_left
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor, gamma, log
from operator import mul
from functools import reduce
from copy import deepcopy

sys.setrecursionlimit(2147483647)
INF = 10 ** 20
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): pass
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]


n, mod = LI()
G = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = LI()
    G[a - 1] += [b - 1]
    G[b - 1] += [a - 1]

dp = [-1] * n
par = [-1] * n
def f(u):
    ret = 1
    for v in G[u]:
        if v == par[u]:
            continue
        par[v] = u
        ret = ret * f(v)
    dp[u] = ret
    if u: return ret + 1

f(0)
ans = [0] * n
ans[0] = dp[0]
par_acc = [1] * n
dp2 = [1] * n
q = deque([0])
while q:
    u = q.pop()
    ans[u] = dp[u] * dp2[u] % mod
    L1 = [1]
    L2 = []
    D = {}
    cnt = 0
    for v in G[u]:
        if par[u] == v:
            continue
        L1 += [dp[v] + 1]
        L2 += [dp[v] + 1]
        D[cnt] = v
        q += [v]
        cnt += 1
    L2 += [1]
    if len(L1) > 2:
        for i in range(len(L1) - 2):
            L1[i + 2] = L1[i + 2] * L1[i + 1] % mod
            L2[-i - 3] = L2[-i - 3] * L2[-i - 2] % mod
    for j in D:
        dp2[D[j]] = (L1[j] * L2[j + 1] * dp2[u] + 1) % mod

print(*ans, sep="\n")


