#!/usr/bin/env python3
import sys
sys.setrecursionlimit(300000)


def solve(N: int, K: int, a: "List[int]"):
    a.sort(reverse=True)
    dp = [False] * K
    dp[0] = True
    ret = 0
    for i in range(N):
        for j in range(K - 1, -1, -1):
            if dp[j]:
                if j + a[i] >= K:
                    ret = i + 1
                else:
                    dp[j + a[i]] = True
    print(N - ret)
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    K = int(next(tokens))  # type: int
    a = [ int(next(tokens)) for _ in range(N) ]  # type: "List[int]"
    solve(N, K, a)

if __name__ == '__main__':
    main()
