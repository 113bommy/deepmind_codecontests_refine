N, S = map(int, input().split())
A = list(map(int, input().split()))

MOD = 998244353

dp = [0] * (S + 1)
dp[0] = 1

for i in range(N):
    ai = A[i]
    for j in range(S, -1, -1):
        dp[j] = 2 * dp[j]
        if j - ai >= 0:
            dp[j] += dp[j - ai]
        dp[j] %= MOD

print(dp[S])
