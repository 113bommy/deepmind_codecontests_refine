#!/usr/bin/env python3
import sys
input = sys.stdin.readline
from collections import deque

n, k = map(int, input().split())
radius = k // 2
edge = [[] for _ in range(n)]
uv = []
for _ in range(n - 1):
    a, b = map(int, input().split())
    a -= 1; b -= 1
    edge[a].append(b)
    edge[b].append(a)
    uv.append((a, b))

def dfs(p, v, d):
    ret = 0
    st = []
    st.append((p, v, d))
    while st:
        p, v, d = st.pop()
        if d > radius:
            ret += 1
        for nv in edge[v]:
            if nv == p:
                continue
            st.append((v, nv, d+1))
    return ret

ans = n 
if k % 2 == 0:
    for i in range(n):
        ret = dfs(-1, i, 0)
        ans = min(ans, ret)
else:
    for u, v in uv:
        ret = dfs(u, v, 0) + dfs(v, u, 0)
        ans = min(ans, ret)

print(ans)