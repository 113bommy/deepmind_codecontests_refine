N = int(input())
*A, = map(int, input().split())
dp = [[0] * (N+1) for _ in range(N+1)]
for n in range(1, N+1):
    for i in range(N-n+1):
        j = i + n
        if (N - n) % 2 == 0: # first player
            dp[i][j] = max(dp[i+1][j] + A[i], dp[i][j-1] + A[j-1])
        else: # second player
            dp[i][j] = min(dp[i+1][j] - A[i], dp[i][j-1] - A[j-1])
print(dp[0][N])