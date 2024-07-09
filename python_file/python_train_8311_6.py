#!/usr/bin/env python3

import sys
import math
from bisect import bisect_right as br
from bisect import bisect_left as bl
sys.setrecursionlimit(2147483647)
from heapq import heappush, heappop,heappushpop
from collections import defaultdict
from itertools import accumulate
from collections import Counter
from collections import deque
from operator import itemgetter
from itertools import permutations
mod = 10**9 + 7
inf = float('inf')
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))


n = I()
edge = [[] for _ in range(n)]
for v in range(1,n):
    u = I()-1
    edge[u].append(v)

dp = [None]*n
def dfs(s):
    if dp[s] != None:
        return dp[s]
    if edge[s] == []:
        dp[s] = 0
        return 0
    tmp = []
    for v in edge[s]:
        tmp.append(dfs(v))
    tmp.sort(reverse=True)
    m = 0
    for i,j in enumerate(tmp):
        m = max(m,(i+1)+j)
    dp[s] = m
    return m

dfs(0)
print(dp[0])
