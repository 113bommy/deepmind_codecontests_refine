h, n = map(int, input().split())
ab = []
for _ in range(n):
  a, b = map(int, input().split())
  ab.append((a, b))
dp = [0] * (h+1)
for c in range(1, h+1):
  dp[c] = min([dp[max(0, c-a)] + b for a, b in ab])
print(dp[-1])