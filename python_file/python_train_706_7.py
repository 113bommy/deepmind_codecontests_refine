def main():

    N, K = map(int, input().split())
    a = list(map(int, input().split()))
    dp = [[0]*(K+1) for i in range(N+1)]
    import collections
    dp[0][K] = 1
    mod = 10**9 + 7
    # dp[i][j] i人目まで配って、残りがj個の方法の数
    s = [0]*(K+2)
    for i in range(1, N+1):
        tmp = 0
        for j in range(K, -1, -1):
            s[j] = (s[j+1] + dp[i-1][j]) % mod
        for j in range(K, -1, -1):
            tmp = s[j] - s[min(K, j+a[i-1]) + 1]
            tmp %= mod
            dp[i][j] = tmp

    print(dp[-1][0])


main()
