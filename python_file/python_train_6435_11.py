k = list(map(int, list(input())))
n = len(k)
d = int(input())
dp = [[[0]*d for _ in range(2)] for _ in range(n+1)]
dp[0][0][0] = 1
mod = 10**9 + 7
for s in (0,1):
  for i in range(n):
    for j in range(10 if s else k[i]+1):
      for m in range(d):
        dp[i+1][s|(j<k[i])][(m+j)%d] = (dp[i+1][s|(j<k[i])][(m+j)%d] + dp[i][s][m]) % mod
print((dp[n][0][0] + dp[n][1][0] - 1) % mod)