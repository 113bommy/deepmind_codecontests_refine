MOD = 10 ** 9 + 7
S = input()
dp = [0] * 13
dp[0] = 1

for i in range(len(S)):
    cdp = [0] * 13
    tmpS = 0
    if S[i] == '?':
        tmpS = -1
    else:
        tmpS = int(S[i])
    for j in range(10):
        if tmpS != -1 and tmpS != j: continue
        for k in range(13):
            cdp[(k * 10 + j) % 13] += dp[k]
            cdp[(k * 10 + j) % 13] %= MOD

    dp = cdp[:]
print(dp[5])