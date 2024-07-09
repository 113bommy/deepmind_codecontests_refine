def calc(n, to_metal, to_acorn):
    mas = tuple(zip(to_metal, to_acorn))
    dp = list(range(n + 1))
    for i in range(n + 1):
        for m, a in mas:
            if i >= m:
                dp[i] = max(dp[i], dp[i - m] + a)
    return dp[n]


def main():
    N = int(input())
    a = tuple(map(int, input().split()))
    b = tuple(map(int, input().split()))

    N = calc(N, a, b)  # 1 周目 : dp[巣から持ってきたドングリ数] = 取引所 B で持てる最大ドングリ数
    N = calc(N, b, a)  # 2 周目 : dp[取引所 B から持ってきたドングリ数] = 巣に持ち帰れる最大ドングリ数
    print(N)


if __name__ == '__main__':
    main()
