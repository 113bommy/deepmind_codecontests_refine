N, S = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353

dp = [0] * (S + 1)
ans = 0

for i, a in enumerate(A):
    for s in range(S + 1)[:: -1]:
        if s + a <= S:
            dp[s + a] += dp[s]
    if a <= S:
        dp[a] += (i + 1)
    ans += dp[S]

print(ans % MOD)