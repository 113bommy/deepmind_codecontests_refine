def solve():
    MOD = 10**9 + 7

    strN = input().rstrip()
    D = int(input())

    maxD = len(strN)

    dp = [[[0]*(D) for j in range(2)] for i in range(maxD+1)]
    dp[0][0][0] = 1
    for d, Nd in enumerate(strN):
        Nd = int(Nd)
        for isLtN in range(2):
            for modD in range(D):
                dp[d][isLtN][modD] %= MOD
                for x in range(10):
                    if not isLtN and x > Nd: continue
                    isLtN2 = isLtN or x < Nd
                    modD2 = (modD+x) % D
                    dp[d+1][isLtN2][modD2] += dp[d][isLtN][modD]

    print((dp[-1][0][0] + dp[-1][1][0] - 1) % MOD)


solve()
