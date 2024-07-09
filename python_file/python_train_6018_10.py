S = input()
dp = [[0]*13 for _ in [0]*-~len(S)]
dp[0][0] = 1
mod = 10**9 + 7

for i, s in enumerate(S):
    if s == '?':
        d = dp[i+1]
        for j in range(13):
            for k in range(10):
                x = (j*10+k) % 13
                d[x] = (d[x] + dp[i][j]) % mod
    else:
        for j in range(13):
            dp[i+1][(j*10+int(s)) % 13] = dp[i][j]
print(dp[-1][5] % mod)
