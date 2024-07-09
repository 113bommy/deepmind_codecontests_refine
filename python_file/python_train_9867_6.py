#!/usr/bin/env python3
import sys
input = sys.stdin.readline

a, b, c, d = map(int, input().split())
dp = [[0] * (d - b + 1) for _ in range(c - a + 1)]

dp[0][0] = 1
for i in range(c - a + 1):
    for j in range(d - b + 1):
        if i > 0:
            dp[i][j] += dp[i-1][j] * (b+j)
        if j > 0:
            dp[i][j] += dp[i][j-1] * (a+i)
        if i > 0 and j > 0:
            dp[i][j] -= dp[i-1][j-1] * (b+j-1) * (a+i-1)
        dp[i][j] %= 998244353

print(dp[-1][-1])