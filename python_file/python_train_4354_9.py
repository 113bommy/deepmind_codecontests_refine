def p_l_2():
    n = int(input())
    *a, = map(int, input().split())
    # dp[i][j]は区間[i,j]が残っているときの最大化
    dp = [[-1] * n for _ in range(n)]

    for i in range(n):
        for l in range(n - i):
            r = l + i
            if l == r:
                dp[l][r] = a[l]
            else:
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1])
    print(dp[0][n - 1])


if __name__ == '__main__':
    p_l_2()
