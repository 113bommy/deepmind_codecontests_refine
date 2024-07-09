#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys

k = 0
l = 0
acc = None

def count_up(y1, x1, y2, x2):
    global acc, l
    if y1 > y2 or x1 > x2:
        return 0
    y2 += 1
    x2 += 1
    return  acc[y2][x2] - acc[y1][x2] - acc[y2][x1] + acc[y1][x1]

def main():
    global acc, k, l
    n, k = map(int, sys.stdin.readline().split())
    xycs = (map(lambda x: int(x) if x != 'B' and x != 'W' else x,
                 line.split()) for line in sys.stdin.readlines())

    l = k * 2
    yxs = (((y + k) % l, x % l) if c == 'W' else (y % l, x % l) for x, y, c in xycs)

    acc = [[0] * (l + 1) for _ in range(l + 1)]
    for y, x in yxs:
        acc[y + 1][x + 1] += 1
    for j in range(l):
        for i in range(l):
            acc[j + 1][i + 1] += acc[j + 1][i] + acc[j][i + 1] - acc[j][i]

    max_cnt = 0
    for j in range(k):
        for i in range(k):
            cnt = count_up(0, 0, j - 1, i - 1) + count_up(0, i + k, j - 1, l - 1) + count_up(j, i, j + k - 1, i + k - 1) + count_up(j + k, 0, l - 1, i - 1) + count_up(j + k, i + k, l - 1, l - 1)
            max_cnt = max(max_cnt, max(n - cnt, cnt))

    print(max_cnt)

if __name__ == '__main__':
    main()
