N,M = list(map(int, input().split()))
S = list(map(int, input().split())) #N
T = list(map(int, input().split())) #M

MOD = 10**9+7

dp = [[0]*M for _ in range(N)]
# dp[n][m] Sのn文字目，Tのm文字目までの場合の数

dp[0][0] = 1 + int(S[0] == T[0])

for i in range(1,N):
  dp[i][0] = dp[i-1][0] + int(S[i]==T[0])
  
for j in range(1,M):
  dp[0][j] = dp[0][j-1] + int(T[j]==S[0])
  
for n in range(1,N):
  for m in range(1,M):
    dp[n][m] = (dp[n-1][m] + dp[n][m-1] - dp[n-1][m-1] + dp[n-1][m-1]*int(S[n]==T[m]))%MOD
    

#print(dp)
print(dp[N-1][M-1])