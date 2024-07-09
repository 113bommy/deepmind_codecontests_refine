a, b, c, d = map(int, input().split())
MOD = 998244353

dp = [[0] * (d - b + 1) for _ in range(c - a + 1)]

dp[0][0] = 1

for x in range(1, d - b + 1):
    dp[0][x] = dp[0][x - 1] * a % MOD
for y in range(1, c - a + 1):
    dp[y][0] = dp[y - 1][0] * b % MOD

for x in range(1, c - a + 1):
    for y in range(1, d - b + 1):
        dp[x][y] = (dp[x - 1][y] * (b + y) + dp[x][y - 1] * (a + x) - dp[x - 1][y - 1] * (a + x - 1) * (b + y - 1)) % MOD

print(dp[-1][-1])