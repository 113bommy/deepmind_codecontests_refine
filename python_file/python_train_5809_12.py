def main():
    from bisect import bisect_right

    N, M = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    def calc(x):
        tmp = 0
        for a in A:
            tmp += N - bisect_right(A, x - a - 0.5)
        return tmp

    l = 0
    r = 3 * 10 ** 5
    while r - l > 1:
        mid = (l + r) // 2
        if calc(mid) >= M:
            l = mid
        else:
            r = mid

    B = [0] * (N + 1)
    for i in range(N):
        B[i + 1] = B[i] + A[i]

    ans = 0
    for a in A:
        tmp = bisect_right(A, r - a - 0.5)
        M -= (N - tmp)
        ans += a * (N - tmp) + (B[-1] - B[tmp])

    ans += M * l
    print (ans)

if __name__ == '__main__':
    main()