K = input()
K_int = int(K)
digit = len(K)
D = int(input())
MOD = 10**9 + 7

# dp[d][r][i] : (d+1)桁目の数がiで、それまでの桁の数の和をDで割ったときの余りがrとなる組合せ
dp = [[[0]*10 for r in range(D)] for d in range(digit)]

for i in range(10):
  dp[0][i%D][i] += 1

for d in range(1, digit):
  for r in range(D):
    s = sum(dp[d-1][r])
    for i in range(10):
      dp[d][(r+i)%D][i] += s
      dp[d][(r+i)%D][i] %= MOD

ans = 0
r = 0
for _d, k in enumerate(K, 1):
  d = digit - _d
  k = int(k)
  if _d == 1:
    for i in range(1, k):
      ans += dp[d][0][i]
      ans %= MOD
  else:
    for i in range(1, 10):
      ans += dp[d][0][i]
      ans %= MOD
    
    for i in range(k):
      ans += dp[d][r][i]
      ans %= MOD
  
  r = (r-k)%D

e = 0
for i in K:
  e += int(i)
  e %= D

if e % D == 0:
  ans += 1
  ans %= MOD

print(ans)