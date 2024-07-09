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
mod = 10 ** 9 + 7

n =I()
G = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = LI()
    G[a - 1] += [b - 1]
    G[b - 1] += [a - 1]

fac = [1] * (n + 1)
inv = [1] * (n + 1)
for j in range(1, n + 1):
    fac[j] = fac[j-1] * j % mod

inv[n] = pow(fac[n], mod-2, mod)
for j in range(n-1, -1, -1):
    inv[j] = inv[j+1] * (j+1) % mod

def comb(n, r):
    if r > n or n < 0 or r < 0:
        return 0
    return fac[n] * inv[n - r] * inv[r] % mod

v_num = [-1] * n
par = [-1] * n
def f(u):
    ret = 1
    for v in G[u]:
        if v == par[u]:
            continue
        par[v] = u
        ret += f(v)
    v_num[u] = ret
    if u: return ret

f(0)
dp = [0] * n

def tree_dp(x):
    c = 1
    remain_v = v_num[x] - 1
    for y in G[x]:
        if y == par[x]:
            continue
        c = c * tree_dp(y) * comb(remain_v, v_num[y]) % mod
        remain_v -= v_num[y]
    dp[x] = c
    if x: return c

tree_dp(0)
ans = [0] * n

def dfs(d):
    e = 1
    inv_e = pow(comb(n - 1, v_num[d]) * dp[d], mod - 2, mod)
    ans[d] = dp[d] * ans[par[d]] * comb(n - 1, v_num[d] - 1) * inv_e % mod

q = deque([0])
ans[0] = dp[0]
while q:
    g = q.pop()
    for h in G[g]:
        if h == par[g]:
            continue
        dfs(h)
        q += [h]

for j in ans:
    print(j)

