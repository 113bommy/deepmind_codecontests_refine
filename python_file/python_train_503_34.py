MAX=2500
n,a=map(int,input().split())
x=list(map(int,input().split()))
# dp[i][j][k] := x[0:i]のカードからj枚とって合計がkとなる取り方の数
dp = [[[0] * (MAX+1) for _ in range(n+1)] for _ in range(n+1)]
dp[0][0][0] = 1

for i in range(n):
  for j in range(0,n+1):
    for k in range(0, MAX+1):
      dp[i+1][j][k] += dp[i][j][k] # i番目のカードを取らない
  for j in range(0,n):
    for k in range(0, MAX+1-x[i]):
      dp[i+1][j+1][k+x[i]] += dp[i][j][k] # i番目のカードを取る

ans = 0
for i in range(1,n+1):
  ans += dp[n][i][a*i]
print(ans)
