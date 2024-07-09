MOD = 10 ** 9 + 7

N, K = map(int, input().split())
A = list(map(int, input().split()))

if K == 0:
    print (1)
    exit()

dp = [[0] * (K + 1) for _ in range(N + 1)]
for j in range(K + 1):
    dp[N][j] = 1
# dp[N][0] = 1
# print (dp[N])
for i in range(N - 1, -1, -1):
    for j in range(K + 1):
        if j <= A[i]:
            dp[i][j] = dp[i + 1][j]
        else:
            dp[i][j] = dp[i + 1][j] - dp[i + 1][j - A[i] - 1]
    # print (i)
    # print (dp[i])
    for j in range(K):
        dp[i][j + 1] += dp[i][j]
        dp[i][j + 1] %= MOD
    # print (dp[i])
    
print ((dp[0][K] - dp[0][K - 1]) % MOD)