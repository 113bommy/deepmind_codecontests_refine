import itertools

N, K = map(int, input().split())
A = tuple(map(int, input().split()))

MOD = 10 ** 9 + 7

dp = [[0] * (K + 1) for _ in range(N + 1)]
dp[0][0] = 1
for i in range(1, N + 1):
    S = [0] + list(itertools.accumulate(dp[i - 1]))
    for j in range(K + 1):
        dp[i][j] = (S[j + 1] - S[max(0, j - A[i - 1])]) % MOD
print(dp[N][K])
