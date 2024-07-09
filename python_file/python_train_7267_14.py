import sys
from collections import Counter

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def main():
    n = int(input())
    aa = list(map(int, input().split()))
    cnt_aa = Counter(aa)
    nc3 = cnt_aa[3]
    nc2 = cnt_aa[2]
    nc1 = cnt_aa[1]
    dp = [[[0] * (n + 1) for _ in range(nc3 + nc2 + 1)] for _ in range(nc3 + 1)]
    for c3 in range(nc3 + 1):
        for c2 in range(nc2 + nc3 - c3 + 1):
            if c3 + c2 > n: break
            for c1 in range(n + 1):
                s = c1 + c2 + c3
                if s > n: break
                if c1 > 0: dp[c3][c2][c1] += (dp[c3][c2][c1 - 1] + n / s) * c1 / s
                if c2 > 0: dp[c3][c2][c1] += (dp[c3][c2 - 1][c1 + 1] + n / s) * c2 / s
                if c3 > 0: dp[c3][c2][c1] += (dp[c3 - 1][c2 + 1][c1] + n / s) * c3 / s
    print(dp[nc3][nc2][nc1])

main()
