def main():
    from collections import namedtuple

    Ratio = namedtuple('Ratio', 'gold, silver copper')

    def trade(n, Rfrm, Rto):
        Df = Ratio(*(t - f for f, t in zip(Rfrm, Rto)))
        dp = [n] * (n + 1)
        for acorn in range(1, n + 1):
            dp[acorn] = max(
                dp[acorn],
                0 if acorn < Rfrm.gold else dp[acorn - Rfrm.gold] + Df.gold,
                0 if acorn < Rfrm.silver else dp[acorn - Rfrm.silver] + Df.silver,
                0 if acorn < Rfrm.copper else dp[acorn - Rfrm.copper] + Df.copper
            )
        return dp[n]

    n = int(input())
    Ra = Ratio(*map(int, input().split()))
    Rb = Ratio(*map(int, input().split()))

    ret = trade(n=n, Rfrm=Ra, Rto=Rb)
    ret = trade(n=ret, Rfrm=Rb, Rto=Ra)
    print(ret)


if __name__ == '__main__':
    main()
