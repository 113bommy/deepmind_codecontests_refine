from itertools import accumulate


def solve(n, rev):
    def existence_right(rev_c):
        n2 = n * 2
        acc = [[0] * n2]
        row = [0] * n2
        for x in rev_c:
            row[n2 - x - 1] += 1
            acc.append(list(reversed(list(accumulate(row)))))
        return acc

    # How many white/black ball lower than 'k' righter than index x? (0<=x<=2N-1)
    # cost[color][k][x]
    cost = list(map(existence_right, rev))

    dp = [[0] * (n + 1) for _ in range(n + 1)]
    for w, x in enumerate(rev[0]):
        dp[w + 1][0] = dp[w][0] + cost[0][w][x]
    for b, y in enumerate(rev[1]):
        dp[0][b + 1] = dp[0][b] + cost[1][b][y]
    for w, x in enumerate(rev[0]):
        dpw0, dpw1 = dp[w], dp[w + 1]
        cost_wx, cost_w1 = cost[0][w][x], cost[0][w + 1]
        for b, y in enumerate(rev[1]):
            dpw1[b + 1] = min(dpw0[b + 1] + cost_wx + cost[1][b + 1][x],
                              dpw1[b] + cost_w1[y] + cost[1][b][y])
    return dp[n][n]


n = int(input())
# White/Black 'k' ball is what-th in whole row?
rev = [[0] * n, [0] * n]
for i in range(n * 2):
    c, a = input().split()
    a = int(a) - 1
    rev[int(c == 'B')][a] = i
print(solve(n, rev))
