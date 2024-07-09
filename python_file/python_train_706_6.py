N, K = map(int, input().split())
A = list(map(int, input().split()))
MOD = 10**9 + 7

dp = [[0] * (K + 1) for _ in range(N + 1)]  # dp[child][candy] 残りcandy個の場合の数
dp[0][K] = 1

for child in range(1, N + 1):
    sumDp = [0] * (K + 2)
    for i in range(1, K + 2)[:: -1]:
        sumDp[i - 1] += sumDp[i] + dp[child - 1][i - 1]

    for candy in range(K + 1):
        dp[child][candy] = (sumDp[candy] - sumDp[min(K, candy + A[child - 1]) + 1]) % MOD

print(dp[N][0] % MOD)