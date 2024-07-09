import sys
sys.setrecursionlimit(10**6)

n = int(input())

neighbor = [[] for _ in range(n + 1)]

for i in range(n - 1):
    x, y = map(int, input().split())
    neighbor[y].append(x)
    neighbor[x].append(y)

mod = 10**9 + 7
dp = [[0] * 2 for _ in range(n + 1)]


def dfs(i, bw, p):
    if dp[i][bw] != 0:
        return dp[i][bw]

    dp[i][bw] = 1
    for j in neighbor[i]:
        if j == p:
            continue

        if bw == 0:  # black
            dp[i][0] = (dp[i][0] * dfs(j, 1, i)) % mod
        else:  # white
            dp[i][1] = (dp[i][1] * (dfs(j, 0, i) + dfs(j, 1, i))) % mod

    return dp[i][bw]


print((dfs(1, 0, 0) + dfs(1, 1, 0)) % mod)
