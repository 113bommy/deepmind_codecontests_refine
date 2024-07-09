R = lambda: map(int, input().split())
n, m = R()
g = [input() for _ in range(n)]
f = [[0 for j in range(m)] for i in range(n)]
res = []
for i in range(n):
    for j in range(m):
        if g[i][j] == '*':
            dd = 0
            for d in range(1, 101):
                if i >= d and i + d < n and j >= d and j + d < m:
                    if g[i - d][j] == '*' and g[i + d][j] == '*' and g[i][j - d] == '*' and g[i][j + d] == '*':
                        f[i][j] = 1
                        f[i - d][j] = 1
                        f[i + d][j] = 1
                        f[i][j - d] = 1
                        f[i][j + d] = 1
                        dd = d
                    else:
                        break
                else:
                    break
            if dd >= 1:
                res.append([i + 1, j + 1, dd])
for i in range(n):
    for j in range(m):
        if g[i][j] == '*' and f[i][j] == 0:
            print(-1)
            exit(0)
print(len(res))
for r in res:
    print(' '.join(map(str, r)))