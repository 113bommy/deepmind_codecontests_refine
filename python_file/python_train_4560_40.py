def main():
    N, K, *I = map(int, open(0).read().split())
    A, F = I[:N], I[N:]

    A.sort()
    F.sort(reverse=True)

    ng, ok = -1, 10 ** 12
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if sum(max(0, a - mid // f) for a, f in zip(A, F)) <= K:
            ok = mid
        else:
            ng = mid

    print(ok)


if __name__ == '__main__':
    main()
