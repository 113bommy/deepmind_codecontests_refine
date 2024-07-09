from heapq import heappush, heappop
import collections
import math
import heapq
from collections import defaultdict
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7
inf = float("inf")


def main():
    N = int(input())
    E = {}
    for i in range(0, N+1):
        E[i] = []
    for i in range(N-1):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        E[a].append(b)
        E[b].append(a)

    dp = [[0 for i in range(2)] for j in range(100100)]

    def dfs(c, p):
        dp[c][0], dp[c][1] = 1, 1
        for to in E[c]:
            if to != p:
                dfs(to, c)
                dp[c][0] *= dp[to][0] + dp[to][1]
                dp[c][1] *= dp[to][0]

    dfs(0, -1)

    ans = (dp[0][0] + dp[0][1]) % MOD
    print(ans)


if __name__ == '__main__':
    main()
