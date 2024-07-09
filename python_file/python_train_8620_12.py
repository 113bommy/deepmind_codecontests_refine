def solve():
    MOD = 10**9 + 7

    N = int(input())
    Ass = [tuple(map(int, input().split())) for _ in range(N)]

    Sss = [[] for _ in range(N+1)]
    for S in range(1<<N):
        num1 = bin(S).count('1')
        Sss[num1].append(S)

    dp = [0] * (1<<N)
    dp[0] = 1
    for iM, Ss in enumerate(Sss[:-1]):
        for S in Ss:
            dp[S] %= MOD
            for iW in range(N):
                if S & (1<<iW) == 0 and Ass[iM][iW]:
                    S2 = S | (1<<iW)
                    dp[S2] += dp[S]

    print(dp[-1] % MOD)


solve()
