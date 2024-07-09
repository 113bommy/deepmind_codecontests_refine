#!/usr/bin/python3
import sys
input = lambda: sys.stdin.readline().strip()
h, w = [int(x) for x in input().split()]
g = [input() for i in range(h)]
dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
hit = [[[0 for j in range(w)] for i in range(h)] for dire in dirs]
for d, dire in enumerate(dirs):
    di, dj = dire
    for i in range(h) if di < 0 else reversed(range(h)):
        for j in range(w) if dj < 0 else reversed(range(w)):
            if g[i][j] != '#':
                hit[d][i][j] = (hit[d][i + di][j + dj] if 0 <= i + di < h and 0 <= j + dj < w else 0) + 1
print(max(sum(hit[d][i][j] for d in range(len(dirs))) - 3 for i in range(h) for j in range(w) if g[i][j] != '#'))