#!/usr/bin/env python3
a = [0] + list(map(int, list(input())))
n = len(a)
dp = [[10 ** 9] * 2 for _ in range(n + 1)]
dp[0][0] = 0
dp[0][1] = 1
for i in range(n):
    dp[i + 1][0] = min(dp[i][0] + a[i], dp[i][1] + 10 - a[i])
    dp[i + 1][1] = min(dp[i][0] + a[i] + 1, dp[i][1] + 10 - a[i] - 1)
print(dp[n][0])
