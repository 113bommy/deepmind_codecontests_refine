from collections import deque
from itertools import product
import sys

sys.setrecursionlimit(100000)
input = sys.stdin.readline


def read():
    N = int(input().strip())
    A = map(int, input().strip().split())
    return N, A


def dfs(I, J, K, N, dp):
    for k in range(0, K+1):
        for j in range(0, J+K+1):
            for i in range(0, N+1):
                x = 0.0
                if not(i + j + k > N or i == 0 and j == 0 and k == 0):
                    x += dp[i-1][j] * (i / N) if i > 0 else 0.0
                    x += dp[i+1][j-1] * (j / N) if j > 0 else 0.0
                    x += dp[i][j+1] * (k / N) if k > 0 else 0.0
                    x += 1.0
                    x *= N / (i + j + k)
                dp[i][j] = x
    return dp[I][J]


def solve(N, A):
    dp = [[0.0 for j in range(N + 2)] for i in range(N + 2)]
    C = [0 for i in range(4)]
    for a in A:
        C[a] += 1
    return dfs(C[1], C[2], C[3], N, dp)


if __name__ == "__main__":
    inputs = read()
    print("%s" % solve(*inputs))
