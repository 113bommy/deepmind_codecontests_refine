#!/usr/bin/env python3
import sys
input = sys.stdin.readline
MOD = 10**9 + 7

n = int(input())
s = input().rstrip()

dp = [[0] * n for _ in range(n)]
dp[0] = [1] * n

used = 0
for i, ch in enumerate(s):
    if ch == "<":
        for j in range(n - used - 1, -1, -1):
            if j-1 >= 0:
                dp[i+1][j-1] = dp[i][j]
        for j in range(n - 1, 0, -1):
            dp[i+1][j-1] += dp[i+1][j]
            dp[i+1][j-1] %= MOD
    else:
        for j in range(n - used - 2, -1, -1):
            dp[i+1][j] = dp[i][j]
        for j in range(1, n - used - 1):
            dp[i+1][j] += dp[i+1][j-1]
            dp[i+1][j] %= MOD
    used += 1

# for line in dp:
#     print(line)
print(sum(dp[-1]) % MOD)