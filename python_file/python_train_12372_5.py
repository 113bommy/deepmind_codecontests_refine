def main():
    n = int(input())
    m = [list(map(int, input().split())) for _ in range(n)]

    ans = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            d = m[i][j]
            t = min(m[i][k] + m[k][j] if k != i and k != j else d + 1 for k in range(n))
            if t < d:
                print(-1)
                exit()
            if d < t:
                ans += d

    print(ans)


if __name__ == '__main__':
    main()
