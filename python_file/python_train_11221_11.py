H, N = map(int, input().split())
M = [tuple(map(int, input().split())) for _ in range(N)]

dp = [float('inf') for _ in range(H + 1)]

dp[0] = 0

for a, b in M:
    for i in range(H+1):
        d = min(H, i + a)
        dp[d] = min(dp[d], dp[i] + b)

print(dp[H])