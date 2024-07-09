n, t = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(n)]

ab.sort()

dp = [[0] * t for _ in range(n + 1)]

ans = 0
for i, (a, b) in enumerate(ab):
    for j in range(t):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j])
        if j + a <= t - 1:
            dp[i+1][j+a] = max(dp[i+1][j+a], dp[i][j] + b)
        else:
            ans = max(ans, dp[i][j] + b)

print(ans)
