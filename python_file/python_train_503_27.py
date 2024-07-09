N, A = map(int, input().split())
X = list(map(int, input().split()))

dp = [[[0 for _ in range(3000)] for _ in range(N + 1)] for _ in range(N + 1)]
dp[0][0][0] = 1

for i in range(N):
    for j in range(N):
        for t in range(2501):
            dp[i + 1][j][t] += dp[i][j][t]
            dp[i + 1][j + 1][t + X[i]] += dp[i][j][t]

ans = 0

for i in range(1, N + 1):
    ans += dp[N][i][i * A]

print(ans)
