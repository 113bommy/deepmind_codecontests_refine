INF = float("inf")

N, *XYP = map(int, open(0).read().split())
XYP = list(zip(*[iter(XYP)] * 3))

def solve(XP):
    M = len(XP)
    XP.sort()

    dp = [[INF] * (M + 1) for _ in range(M + 1)]
    dp[0][0] = 0

    for i, (x, p) in enumerate(XP):
        dp[i + 1][0] = dp[i][0] + abs(x) * p

    for l, dpl in enumerate(dp[:M]):
        for r in range(l + 1, M + 1):
            val = INF
            for lx, _ in XP[l:r]:
                cur = 0
                for x, p in XP[l:r]:
                    cur += p * min(abs(x - lx), abs(x))
                val = min(val, cur)

            for i in range(1, M + 1):
                dp[r][i] = min(
                    dp[r][i],
                    val + dpl[i - 1]
                )

    res = [INF] * (N + 1)
    res[:M + 1] = dp[M]
    return res


A = [INF] * (N + 1)
for state in range(1 << N):
    XP, YP = [], []
    for i, (x, y, p) in enumerate(XYP):
        if (state >> i) & 1:
            XP.append((x, p))
        else:
            YP.append((y, p))

    X, Y = solve(XP), solve(YP)
    for i in range(N + 1):
        for j in range(N + 1 - i):
            A[i + j] = min(A[i + j], X[i] + Y[j])

for a in A:
    print(a)