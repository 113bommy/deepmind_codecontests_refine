def main():
    n, m = map(int, input().split())
    st = [list(map(int, input().split())) for _ in range(m)]

    g = [[] for _ in range(n)]

    for s, t in st:
        s -= 1
        t -= 1
        g[s].append(t)

    deg = [len(x) for x in g]

    dp = [0] * n

    for u in range(n-1)[::-1]:
        now = 0
        for v in g[u]:
            now += dp[v]

        now /= deg[u]
        now += 1
        dp[u] = now

    ans = dp[0]

    for u in range(n-1):
        if deg[u] == 1:
            continue

        d = g[u][0]
        for v in g[u]:
            if dp[d] < dp[v]:
                d = v

        dp2 = [0] * n
        for x in range(n - 1)[::-1]:
            now = 0
            for y in g[x]:
                if x == u and y == d:
                    continue
                now += dp2[y]

            if x == u:
                now /= deg[x] - 1
            else:
                now /= deg[x]

            now += 1
            dp2[x] = now

        ans = min(ans, dp2[0])

    print(ans)


if __name__ == "__main__":
    main()
