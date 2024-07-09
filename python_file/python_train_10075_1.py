n, s = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353
W_MAX = s
dp = [0]*(W_MAX+1)
dp[0] = 1
inv_2 = pow(2, MOD-2, MOD)
for a in A:
    for j in reversed(range(W_MAX+1)):
        if W_MAX < j+a:
            continue
        dp[j+a] += dp[j]*inv_2
        dp[j+a] %= MOD

print(dp[-1]*pow(2, n, MOD) % MOD)