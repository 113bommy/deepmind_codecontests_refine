import sys
input = sys.stdin.readline

def solve():
    INF = float('inf')

    def max2(x, y): return x if x >= y else y

    R, C, K = map(int, input().split())
    Vss = [[0]*(C+1) for _ in range(R+1)]
    for _ in range(K):
        r, c, v = map(int, input().split())
        Vss[r][c] = v

    dpMax = [0]*(C+1)
    for i in range(1, R+1):
        dp0 = [0]*(C+1)
        dp1 = [-INF]*(C+1)
        dp2 = [-INF]*(C+1)
        dp3 = [-INF]*(C+1)
        for j in range(1, C+1):
            V = Vss[i][j]
            dp0[j] = max2(dp0[j-1], dpMax[j])
            dp1[j] = max2(dp0[j] + V, dp1[j-1])
            dp2[j] = max2(dp1[j-1] + V, dp2[j-1])
            dp3[j] = max2(dp2[j-1] + V, dp3[j-1])
            dpMax[j] = max(dp0[j], dp1[j], dp2[j], dp3[j])

    ans = dpMax[C]
    print(ans)


solve()
