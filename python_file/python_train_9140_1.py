n = int(input())
pp = list(map(float,input().split()))

dp = [[0]*(n+1) for _ in range(n+1)]
dp[0][0] =1

for i in range(n):
  for j in range(n):
    dp[i+1][j+1] += dp[i][j] * pp[i]
    dp[i+1][j] += dp[i][j] * (1-pp[i])
    
print(sum(dp[-1][(n+1)//2:]))