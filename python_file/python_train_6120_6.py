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
from operator import add, mul, sub

sys.setrecursionlimit(100000)
input = sys.stdin.readline
INF = 2**62-1
EPS = 1.0e-8

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


class Circle:
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r

    def center(self):
        return Point(self.x, self.y)

    def intersection(self, c):
        d = self.center().distance(c.center())
        if d > self.r + c.r:
            return None
        # One circle within other
        if d < abs(self.r - c.r):
            return None
        # coincident circles
        if d == 0 and self.r == c.r:
            return None
        else:
            a = (self.r**2 - c.r**2 + d**2) / (2*d)
            h = math.sqrt(self.r**2-a**2 + sys.float_info.epsilon)
            x2 = self.x+a*(c.x-self.x)/d
            y2 = self.y+a*(c.y-self.y)/d
            x3 = x2+h*(c.y-self.y)/d
            y3 = y2-h*(c.x-self.x)/d

            x4 = x2-h*(c.y-self.y)/d
            y4 = y2+h*(c.x-self.x)/d

            return Point(x3, y3), Point(x4, y4)

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance(self, p):
        return math.sqrt((self.x - p.x)**2 + (self.y - p.y)**2)

class Bisect:
    def __init__(self, func):
        self.__func = func


    def bisect_left(self, x, lo, hi):
        while hi - lo > EPS:
            mid = (lo+hi)/2
            if self.__func(mid) < x:
                lo = mid
            else:
                hi = mid
        return lo

@mt
def slv(N, K, XYC):
    def f(t):
        cs = []
        for x, y, c in XYC:
            cs.append(Circle(x, y, t / c))

        cand = [c.center() for c in cs]
        for i, j in combinations(range(N), r=2):
            p = cs[i].intersection(cs[j])
            if p:
                cand.append(p[0])
                cand.append(p[1])

        ans = 0
        for p in cand:
            tmp = 0
            for c in cs:
                d = c.center().distance(p)
                if d - EPS < c.r:
                    tmp += 1
            ans = max(ans, tmp)
        return ans

    b = Bisect(f)
    return b.bisect_left(K, 0, 10000000)


def main():
    N, K = read_int_n()
    XYC = [read_int_n() for _ in range(N)]
    print(slv(N, K, XYC))


if __name__ == '__main__':
    main()
