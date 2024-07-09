A, B, C, D = map(int, input().split())
MOD = 998244353

dp = [[0] * (D + 2) for _ in range(C + 2)]
dp[A][B] = 1

for h in range(A, C + 1):
    for w in range(B, D + 1):
        d = dp[h][w] % MOD
        dp[h + 1][w] += d * w
        dp[h][w + 1] += d * h
        dp[h + 1][w + 1] -= d * w * h % MOD
print(dp[C][D] % MOD)
