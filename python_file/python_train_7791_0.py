from itertools import permutations
n,m = map(int,input().split())
lrx = [list(map(int,input().split())) for i in range(m)]
lrx.sort(key = lambda x:x[1])
mod = 10**9+7
dp = [[[0 for b in range(max(1,g))] for g in range(max(1,r))] for r in range(n+1)]
dp[0][0][0] = 1
for l,r,t in lrx:
  if t != 1:
    for g in range(l):
      for b in range(max(1,g)):
        dp[r][g][b] = -1
  if t != 2:
    for g in range(l,r):
      for b in range(l):
        dp[r][g][b] = -1
  if t != 3:
    for g in range(l,r):
      for b in range(l,g):
        dp[r][g][b] = -1

for r in range(n):
  for g in range(max(1,r)):
    for b in range(max(1,g)):
      v = dp[r][g][b]
      if v == -1:
        continue
      if dp[r+1][g][b] >= 0:
        dp[r+1][g][b] += v
        dp[r+1][g][b] %= mod
      if dp[r+1][r][b] >= 0:
        dp[r+1][r][b] += v
        dp[r+1][r][b] %= mod
      if dp[r+1][r][g] >= 0:
        dp[r+1][r][g] += v
        dp[r+1][r][g] %= mod
ans = 0
for i in range(n):
  for j in range(max(1,i)):
    if dp[n][i][j] >= 0:
      ans += dp[n][i][j]
      ans %= mod
print(ans%mod)
