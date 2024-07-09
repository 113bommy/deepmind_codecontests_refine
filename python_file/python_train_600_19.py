import sys
stdin = sys.stdin

sys.setrecursionlimit(10 ** 7)

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x) - 1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

from bisect import bisect_right

n, m = li()
lrc = [list(li()) for _ in range(m)]

# n = 10**5
# m = 10**5
# lrc = [[1, n, 5] for _ in range(m)]

# l -> r の降順にソート
lrc = sorted(lrc, key=lambda x: x[2])
lrc = sorted(lrc, key=lambda x: x[1])
lrc = sorted(lrc, key=lambda x: x[0])
#lrc = sorted((sorted(lrc, key=lambda x: x[1])), key=lambda x: x[0])

# 二分探索で距離更新
INF = float('inf')
dist = [INF]*n
dist[0] = 0

for left_idx, right_idx, ci in lrc:
    left_idx -= 1
    newleft_idx = bisect_right(dist, dist[left_idx] + ci)
    for idx in range(newleft_idx, right_idx):
        dist[idx] = dist[left_idx] + ci

if dist[-1] == INF:
    print(-1)
else:
    print(dist[-1])
