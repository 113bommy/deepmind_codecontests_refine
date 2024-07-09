from sys import stdin
readline = stdin.readline

R, C, K = map(int, readline().split())

goods = [[0] * C for _ in range(R)]
for _ in range(K):
    r, c, v = map(int, readline().split())
    goods[r - 1][c - 1] = v

n = [0] * (C + 1)
for i in range(R):
    c = [0] * 4
    c[0] = n[0]
    for j in range(C):
        if goods[i][j] != 0:
            for k in range(2, -1, -1):
                if c[k] + goods[i][j] > c[k + 1]:
                    c[k + 1] = c[k] + goods[i][j]
        for k in range(4):
            if c[k] > n[j]:
                n[j] = c[k]
        if n[j + 1] > c[0]:
            c[0] = n[j + 1]

print(max(c))
