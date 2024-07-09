def solve():
    INF = 10**12

    def max2(x, y): return x if x >= y else y
    def min2(x, y): return x if x <= y else y

    N, K = map(int, input().split())
    Hs = [0] + list(map(int, input().split()))

    dp = [[INF]*(N+1) for _ in range(N+1)]
    dp[0][0] = 0
    for i in range(1, N+1):
        H = Hs[i]
        diffs = []
        for iPrev in range(i):
            diff = max2(0, H-Hs[iPrev])
            diffs.append(diff)
        dp[i][0] = 0
        dp[i][1] = H
        for j in range(2, min(i, N-K)+1):
            for iPrev in range(i):
                dp[i][j] = min2(dp[i][j], dp[iPrev][j-1]+diffs[iPrev])

    ans = min(dpi[N-K] for dpi in dp)
    print(ans)


solve()
