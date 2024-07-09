#!/usr/bin/env python3
import sys
from collections import defaultdict
INF = float("inf")


def bit_sum(n):
    return bin(n).count("1")


def solve(N: int, A: "List[int]", B: "List[int]"):

    DP = [[INF]*51 for _ in range(1 << N)]
    DP[0][0] = 0

    for bit in range(1 << N):

        ketawa = bit_sum(bit)

        # bit集合で表現されない値の位置を確認する
        rest = []
        counter = ketawa
        for i in range(N):
            if bit & (1 << i):
                continue
            rest.append((i, counter))
            counter += 1

        # 最後の数がsである場合から配るDP
        for s in range(51):
            if DP[bit][s] == INF:
                continue
            for orig, curr in rest:
                # 元の並びでorig番目にあったカードをketawa番目に移動する。
                # 表の値が確定する
                if (orig-ketawa) % 2 == 0:
                    front = A[orig]
                else:
                    front = B[orig]
                # 値がs以上なら、単調増加にできる
                if front >= s:
                    DP[bit | 1 << orig][front] = min(DP[bit | 1 << orig][front],
                                                     DP[bit][s]+abs(curr-ketawa))
    ans = min(DP[-1])
    if ans == INF:
        print(-1)
    else:
        print(ans)


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    A = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    B = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, A, B)


if __name__ == '__main__':
    main()
