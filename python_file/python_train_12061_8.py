N, W = map(int, input().split())

WV = [tuple(map(int, input().split())) for _ in range(N)]
W0 = WV[0][0]
R = N * 3

dp = [[-10**18] * (R + 1) for _ in range(N + 1)]
dp[0][0] = 0

for w, v in WV:
    w -= W0
    for n in range(N)[::-1]:
        for i in range(R)[::-1]:
            if i + w <= R:
                dp[n + 1][i + w] = max(dp[n + 1][i + w], dp[n][i] + v)

ans = 0
for n in range(N + 1):
    for w in range(R + 1):
        if n * W0 + w <= W:
            ans = max(ans, dp[n][w])
print(ans)
