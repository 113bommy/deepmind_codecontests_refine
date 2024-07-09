from itertools import accumulate

mod = 10 ** 9 + 7

N, K, *A = map(int, open(0).read().split())

dp = [1] + [0] * K
for a in A:
    S = [0] + list(accumulate(dp))
    for i in range(K + 1):
        dp[i] = (S[i + 1] - S[max(0, i - a)]) % mod

print(dp[K])