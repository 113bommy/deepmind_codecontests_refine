import sys
readline = sys.stdin.readline

# dp[i][j][k] = 寿司が3つの皿がi個、2つの皿がj個、1つの皿がk個からの操作回数の期待値
# dp[0][0][0] = 0で正しいので、ここから順に埋めていけばよい。

N = int(readline())
A = list(map(int,readline().split()))

cnt = [0] * 4

for a in A:
  cnt[a] += 1

dp = [[[0 for k in range(N + 2)] for j in range(N + 2)] for i in range(N + 2)]

for i in range(N + 1):
  for j in range(N + 1):
    for k in range(N + 1):
      nonzero = i + j + k
      if nonzero == 0:
        continue
      dp[i][j][k] = N / nonzero
      if i - 1 >= 0:
        dp[i][j][k] += dp[i - 1][j + 1][k] * i / nonzero
      if j - 1 >= 0:
        dp[i][j][k] += dp[i][j - 1][k + 1] * j / nonzero
      if k - 1 >= 0:
        dp[i][j][k] += dp[i][j][k - 1] * k / nonzero

print(dp[cnt[3]][cnt[2]][cnt[1]])
