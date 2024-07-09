from itertools import accumulate

MOD = 10**9 + 7
N, K = map(int, input().split())
*A, = map(int, input().split())
dp = [0] * (K+1)
dp[K] = 1
for a in A:
    temp = [0] * (K+1)
    for k in range(K+1):
        temp[k - min(a, k)] += dp[k]; temp[k - min(a, k)] %= MOD
        temp[k] -= dp[k]; temp[k] %= MOD
    temp = list(accumulate(temp))
    dp = [(d + t) % MOD for d, t in zip(dp, temp)]
print(dp[0] % MOD)