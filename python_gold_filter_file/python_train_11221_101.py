H, N = [int(_) for _ in input().split()]
AB = [[int(_) for _ in input().split()] for _ in range(N)]
dp = [float('inf')] * 10001
dp[0] = 0
for a, b in AB:
    for i in range(10001 - a):
        dp[i + a] = min(dp[i + a], dp[i] + b)
print(min(dp[H:]))
