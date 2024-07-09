n, m = [int(i) for i in input().split()]
dp = [[float("inf") for i in range(2**n)] for j in range(m+1)]
dp[0][0] = 0

for i in range(m):
    a, _ = [int(_) for _ in input().split()]
    c = sum([2**(int(_)-1) for _ in input().split()])

    for j in range(2**n):
        dp[i+1][j|c] = min(dp[i][j|c], dp[i][j] + a, dp[i+1][j|c])
        dp[i+1][j] = min(dp[i][j], dp[i+1][j])

print([dp[-1][-1], -1][dp[-1][-1] == float("inf")])