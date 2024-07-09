N,M = (int(x) for x in input().split())
S_arr = [int(x) for x in input().split()]
T_arr = [int(x) for x in input().split()]

dp = [[1]*(M+1) for _ in range(N+1)]

mod = 1000000007
for n in range(N):
    for m in range(M):
        if S_arr[n] == T_arr[m]:
            dp[n+1][m+1] = (dp[n+1][m]+dp[n][m+1]) % mod
        else:
            dp[n+1][m+1] = (dp[n+1][m]+dp[n][m+1]-dp[n][m]) % mod
print(dp[N][M])
