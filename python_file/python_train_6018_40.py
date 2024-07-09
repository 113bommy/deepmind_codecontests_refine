S = input()
MOD = 10**9 + 7
M = 13

dp = [0] * M
dp[0] = 1

for s in S:
    newDp = [0] * M
    if s == '?':
        for s in range(10):
            for i in range(M):
                newDp[(i * 10 + s) % M] += dp[i]
    else:
        s = int(s)
        for i in range(M):
            newDp[(i * 10 + s) % M] = dp[i]
    for i in range(M):
        dp[i] = newDp[i] % MOD

print(dp[5])
