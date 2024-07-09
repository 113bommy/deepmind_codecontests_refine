import math
import os
import sys
from collections import deque

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

H, W, K = list(map(int, sys.stdin.readline().split()))
A = [sys.stdin.readline().rstrip() for _ in range(H)]

sh = sw = -1
for h, r in enumerate(A):
    if 'S' in r:
        sh = h
        sw = r.index('S')


def step(h, w):
    return math.ceil(min(h, w, H - h - 1, W - w - 1) / K)


def ok(h, w):
    return 0 <= h < H and 0 <= w < W


dh = [0, 1, 0, -1]
dw = [1, 0, -1, 0]

# 最初の魔法でどこまで端にいけるか
que = deque([(sh, sw, K)])
seen = [[0] * W for _ in range(H)]
seen[sh][sw] = True
min_step = step(sh, sw)
while que:
    sh, sw, k = que.popleft()
    for hh, ww in zip(dh, dw):
        h = sh + hh
        w = sw + ww
        if not ok(h, w) or A[h][w] == '#' or seen[h][w]:
            continue
        if k > 0:
            min_step = min(min_step, step(h, w))
            seen[h][w] = True
            que.append((h, w, k - 1))
print(min_step + 1)
