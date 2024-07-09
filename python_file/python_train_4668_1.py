def solve(s, k):
    n = len(s)
    pdp = [[0] * (k + 1) for _ in range(n + 1)]
    for l in range(n - 1, -1, -1):
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        for r in range(l, n):
            dpr, dpr1 = dp[r], pdp[r - 1]
            inc = 1 if l == r else 2
            is_same = s[l] == s[r]
            for p in range(k + 1):
                if is_same:
                    dpr[p] = dpr1[p] + inc
                else:
                    if p:
                        dpr[p] = max(pdp[r][p], dp[r - 1][p], dpr1[p - 1] + inc)
                    else:
                        dpr[p] = max(pdp[r][p], dp[r - 1][p])
        pdp = dp

    return pdp[-2][k]


print(solve(input(), int(input())))
