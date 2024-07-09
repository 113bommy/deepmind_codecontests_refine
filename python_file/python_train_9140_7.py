n = int(input())
p = list(map(float, input().split()))
dp = [[0.0] * (n + 1) for _ in range(n + 1)]
dp[0][0] = 1.0
for i in range(1, n + 1):
    for j in range(n + 1):
        dp[i][j] = dp[i - 1][j] * (1 - p[i - 1]) + dp[i - 1][j - 1] * p[i - 1]
ans = sum(dp[n][i] for i in range(n // 2 + 1, n + 1))
print(ans)
