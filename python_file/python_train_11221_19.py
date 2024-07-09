H, N = map(int, input().split())
AB = [tuple(map(int, input().split())) for _ in range(N)]

dp = [0] * (H + 1)
for h in range(1, H + 1):
    dp[h] = min([dp[max(h - a, 0)] + b for a, b in AB])

print(dp[-1])
