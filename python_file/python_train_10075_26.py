N, S = map(int, input().split())
MOD = 998244353
A = list(map(int, input().split()))

dp = [[0]*(S+1) for i in range(N+1)]
dp[0][0] = 1
for i, a in  enumerate(A, 1):
  for s in range(S+1):
    dp[i][s] = 2*dp[i-1][s]
    if a <= s:
      dp[i][s] += dp[i-1][s-a]
    dp[i][s] %= MOD

print(dp[-1][-1])