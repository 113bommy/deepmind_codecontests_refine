import math
h, n = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(n)]

dp = [math.inf]*(h+10000)
dp[0] = 0
for a, b in ab:
    for i in range(h+10000):
        dp[i] = min(dp[i], dp[i-a]+b)
print(min(dp[h:]))

# print(dp[:h+100])
