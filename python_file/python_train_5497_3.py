def f_small_products(N, K, MOD=10**9 + 7):
    # 参考: https://atcoder.jp/contests/abc132/submissions/6187073
    sqrt_n = int(N**0.5)

    # num: 0 <= i <= Nについて、N // i の値で同一視できるものの個数が前から格納される
    num = [0 for i in range(2 * sqrt_n + 1)]
    # 1から√N までは、同一視できるものの個数は1つ
    for i in range(1, sqrt_n + 1):
        num[i] = 1
    # √NからN までは、複数の整数が同一視されることがある
    for i in range(1, sqrt_n + 1):
        lo = max(sqrt_n + 1, (N + i + 1) // (i + 1))
        hi = N // i
        num[2 * sqrt_n + 1 - i] = hi - lo + 1

    # dp[n][m]: 最後の整数が m であるような n 個の整数を
    # 並べて条件を満たすようにする場合の数
    dp = [[0 for j in range(2 * sqrt_n + 2)] for i in range(K + 1)]
    dp[0][1] = 1  # 数列の先頭のさらに1個前に1があるとみなす(置き方1通り)
    for i in range(K):
        # 累積和を用いたdpテーブルの更新(imos法)
        for j in range(1, 2 * sqrt_n + 1):
            ways = (dp[i][j] * num[j]) % MOD
            dp[i + 1][1] += ways
            dp[i + 1][2 * sqrt_n + 2 - j] -= ways
        for j in range(1, 2 * sqrt_n + 1):
            dp[i + 1][j] += dp[i + 1][j - 1]

    return sum(a * b for a, b in zip(dp[K], num)) % MOD

N, K = [int(i) for i in input().split()]
print(f_small_products(N, K))