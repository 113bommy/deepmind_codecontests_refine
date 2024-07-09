def solve():
    MOD = 998244353

    N, S = map(int, input().split())
    As = list(map(int, input().split()))

    dp = [[0]*(3) for _ in range(S+1)]
    dp[0][0] = 1
    for A in As:
        for sm in reversed(range(S+1)):
            dp[sm][2] += dp[sm][1] + dp[sm][0]
            if sm-A >= 0:
                dp[sm][2] += dp[sm-A][1] + dp[sm-A][0]
            dp[sm][2] %= MOD
            dp[sm][1] += dp[sm][0]
            if sm-A >= 0:
                dp[sm][1] += dp[sm-A][1] + dp[sm-A][0]
            dp[sm][1] %= MOD

    print(dp[S][2])


solve()
