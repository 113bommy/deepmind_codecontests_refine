def dfs(v, c):
    color[v] = c
    for i in range(n):
        if g[v][i] == 1:
            if color[i] == c:
                return False
            if color[i] == 0 and not dfs(i, -c):
                return False
    return True


n = int(input())
g = []
for i in range(n):
    s = list(map(int, list(input())))
    for j in range(n):
        if s[j] == 0:
            s[j] = 1000000
        if i == j:
            s[j] = 0
    g.append(s)

# 二部グラフ判定
color = [0] * n
nibu = True
for i in range(n):
    if color[i] == 0:
        if not dfs(i, 1):
            nibu = False

if nibu:
    for k in range(n):
        for i in range(n):
            for j in range(n):
                g[i][j] = min(g[i][j], g[i][k] + g[k][j])
    ans = 0
    for i in range(n):
        ans = max(ans, max(g[i]))
    print(ans + 1)
else:
    print(-1)