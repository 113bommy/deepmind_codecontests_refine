s = input()
mod = 10 ** 9 + 7

dp = [1] + [0] * 12
for c in s:
  tmp = dp[:]
  if c == '?':
    dp = [0] * 13
    for n in range(10):
      for i in range(13):
        index = (10 * i + n) % 13
        dp[index] = (dp[index] + tmp[i]) % mod
  else:
    n = int(c)
    for i in range(13):
      dp[(10 * i + n) % 13] = tmp[i]
print(dp[5])