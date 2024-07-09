MOD = 998244353
n, s = map(int, input().split())
nums = list(map(int, input().split()))

dp = [[0] * (s + 1) for _ in range(n + 1)]
dp[0][0] = 1

for i in range(n):
  for j in range(s + 1):
    dp[i + 1][j] += dp[i][j] * 2 % MOD
    if j >= nums[i]:
      dp[i + 1][j] += dp[i][j - nums[i]]
    dp[i + 1][j] %= MOD
print(dp[n][s])