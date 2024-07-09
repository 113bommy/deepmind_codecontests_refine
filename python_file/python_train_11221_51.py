H, N = map(int, input().split())
AB = [[int(x) for x in input().split()] for _ in range(N)]
dp = [float('inf')] * (H + 1)
dp[0] = 0
for h in range(H + 1):
    for a, b in AB:
        h_new = min(h + a, H)
        dp[h_new] = min(dp[h] + b, dp[h_new])
print(dp[-1])