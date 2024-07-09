n, k = map(int, input().split())
l = list(map(int, input().split()))

dp = [-1]*(k+1)
dp[0] = 0

for i in range(1, k+1):
  temp = 1
  for j in range(n):
    if i - l[j] >= 0:
      temp *= dp[i-l[j]]
  dp[i] = 1-temp
      
if dp[k] == 0:
  print('Second')
else:
  print('First')