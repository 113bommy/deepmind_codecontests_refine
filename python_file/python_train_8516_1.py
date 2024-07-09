import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

N = int(sys.stdin.readline())
S = sys.stdin.readline().rstrip()
Q = int(sys.stdin.readline())
K = list(map(int, sys.stdin.readline().split()))


def solve(k):
    ret = 0
    d = 0
    m = 0
    dm = 0
    l = 0
    r = 0
    while r < N:
        if k <= r:
            if S[l] == 'D':
                d -= 1
                dm -= m
            if S[l] == 'M':
                m -= 1
            l += 1

        if S[r] == 'D':
            d += 1
        if S[r] == 'M':
            m += 1
            dm += d
        if S[r] == 'C':
            ret += dm
        r += 1
    return ret


for k in K:
    ans = solve(k)
    print(ans)
