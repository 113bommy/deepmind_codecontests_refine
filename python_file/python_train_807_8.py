n = int(input())
a = sorted([(v,k) for k,v in enumerate(list(map(int, input().split())))], reverse=True)
dp = [[-(10 ** 18)] * (n+1) for i in range(n+1)]
dp[0][0] = 0
for i,(v,k) in enumerate(a):
  for j in range(i+1):
    left = j
    right = n-1-(i-j)
    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + v * abs(k-right))
    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + v * abs(k-left))
print(max(dp[i+1]))