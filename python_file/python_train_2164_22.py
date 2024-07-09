n, m, s = map(int, input().split())
uvab = [list(map(int, input().split())) for _ in range(m)]
cd = [list(map(int, input().split())) for _ in range(n)]


import math

M = 50 * n + 1
s = min(s, M - 1)

dp = [[float('inf')] * M for _ in range(n)]

dp[0][s] = 0
c, d = cd[0][0], cd[0][1]
for jj in range(M):
    dp[0][jj] = min(dp[0][jj], dp[0][s] + max(math.ceil((jj - s) / c), 0) * d)

while True:
    flag = False

    for i in range(m):
        u1, v1, a, b = uvab[i][0] - 1, uvab[i][1] - 1, uvab[i][2], uvab[i][3]
        for u, v in [(u1, v1), (v1, u1)]:
            for j in range(M - a):
                tmp = dp[u][j + a] + b
                if tmp < dp[v][j]:
                    dp[v][j] = tmp
                    flag = True

            c, d = cd[v][0], cd[v][1]
            for jj in range(c, M):
                tmp = dp[v][jj - c] + d
                if tmp < dp[v][jj]:
                    dp[v][jj] = tmp
                    flag = True

    if flag == False:
        break

for t in range(1, n):
    print(min(dp[t]))
