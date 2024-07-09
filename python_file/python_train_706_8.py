from itertools import accumulate

MOD = 10 ** 9 + 7

N, K = map(int, input().split())
As = list(map(int, input().split()))

dp = [0] * (K+1)
dp[0] = 1
for A in As:
    accDP = [0] + list(accumulate(dp))
    accDP = [accDPi % MOD for accDPi in accDP]
    dp = [(accDP[j+1] - accDP[max(0, j-A)]) % MOD for j in range(K+1)]

print(dp[K])
