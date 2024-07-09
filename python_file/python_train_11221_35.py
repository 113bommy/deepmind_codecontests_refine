H, N = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(N)]

dp = [10 ** 18] * (2 * 10 ** 4 + 1)
dp[0] = 0
for a, b in AB:
    for i in range(H):
        dp[i + a] = min(dp[i + a], dp[i] + b)

ans = min(dp[H:])
print(ans)
