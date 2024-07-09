n, c = map(int, input().split())
D = [tuple(map(int, input().split())) for _ in range(c)]
C = [tuple(map(lambda x:int(x)-1, input().split())) for _ in range(n)]

# 全ての色について違和感を記録
dst = [[0, 0, 0] for _ in range(c)]
for ci in range(c):
    for i in range(n):
        for j in range(n):
            c_from = C[i][j]
            dst[ci][(i+j)%3] += D[c_from][ci]

from itertools import permutations
d = 1000*500*500
for p0, p1, p2 in permutations(list(range(c)), 3):
    d = min(d, dst[p0][0] + dst[p1][1] + dst[p2][2])
print(d)
