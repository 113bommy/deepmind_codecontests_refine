# -*- coding: utf-8 -*-
import bisect
import heapq
import math
import random
import sys
from collections import Counter, defaultdict, deque
from decimal import ROUND_CEILING, ROUND_HALF_UP, Decimal
from functools import lru_cache, reduce
from itertools import combinations, combinations_with_replacement, product, permutations
from operator import add, sub

sys.setrecursionlimit(10000)

mod = 10**9 + 7


def read_int():
    return int(input())


def read_int_n():
    return list(map(int, input().split()))


def read_float():
    return float(input())


def read_float_n():
    return list(map(float, input().split()))


def read_str():
    return input().strip()


def read_str_n():
    return list(map(str, input().split()))


def error_print(*args):
    print(*args, file=sys.stderr)


def mt(f):
    import time

    def wrap(*args, **kwargs):
        s = time.time()
        ret = f(*args, **kwargs)
        e = time.time()

        error_print(e - s, 'sec')
        return ret

    return wrap


def mul(a, b):
    return ((a % mod) * (b % mod)) % mod


def power(x, y):
    if y == 0:
        return 1
    elif y == 1:
        return x % mod
    elif y % 2 == 0:
        return power(x, y//2)**2 % mod
    else:
        return power(x, y//2)**2 * x % mod


def div(a, b):
    return mul(a, power(b, mod-2))


@mt
def slv(N, A):

    def perm(n):
        p = 1
        for i in range(1, n+1):
            p = mul(p, i)
        return p

    pn = perm(N)
    sp = [0]
    for i in range(1, N+1):
        sp.append((sp[-1] + div(pn, i)) % mod)

    ans = mul(sp[-1], A[0])
    for i in range(1, N):
        ans += mul(sp[i+1] - sp[1], A[i])
        ans %= mod
        ans += mul(sp[N-i] - sp[0], A[i])
        ans %= mod
    return ans


def main():
    N = read_int()
    A = read_int_n()
    print(slv(N, A))


if __name__ == '__main__':
    main()
