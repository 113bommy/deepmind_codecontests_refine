INF = float("inf")

H, N, *AB = map(int, open(0).read().split())

dp = [0] + [INF] * H

for a, b in zip(*[iter(AB)] * 2):
    for i in range(H + 1):
        idx = min(i + a, H)
        dp[idx] = min(dp[idx], dp[i] + b)

print(dp[H])