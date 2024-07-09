N = int(input())
S = input()
MOD = 10**9 + 7

# dp[j] (i番目のiteration時点): 
#   左から(i+1)番目まで並べ終えたときに、最も右の数が、
#   そのときに残っている(N-i)個の数の中で(j+1)番目に小さい数である場合の数
dp = [1] * N
cum = [[i for i in range(1, N+1)], [0]*N]

for i in range(1, N):
  idx = i%2
  if S[i-1] == '<':
    for j in range(N-i):
      dp[j] = cum[idx-1][j]
      if j == 0:
        cum[idx][0] = dp[j]
      else:
        cum[idx][j] = (cum[idx][j-1] + dp[j]) % MOD
  
  else:
    for j in range(N-i):
      dp[j] = (cum[idx-1][N-i] - cum[idx-1][j]) % MOD
      if j == 0:
        cum[idx][0] = dp[j]
      else:
        cum[idx][j] = (cum[idx][j-1] + dp[j]) % MOD

print(dp[0])