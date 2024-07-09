MOD = 10 ** 9 + 7
S = input()
LS = len(S)
dp = [[0] * 13 for _ in range(LS+1)]
dp[0][0] = 1

for k in range(LS):
    #prev = [x for x in dp]
    #dp = [0] * 13
    s = S[k]
    if s == '?':
        add = range(10)
    else:
        add = [int(s)]
    for i in range(13):
        for a in add:
            dp[k+1][(i*10+a)%13] += dp[k][i]
    dp[k+1] = [x % MOD for x in dp[k+1]]
print(dp[LS][5])