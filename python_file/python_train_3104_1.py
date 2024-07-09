N, M = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

ret = 1
MOD = 10 ** 9 + 7

from collections import Counter
import sys

ca = Counter(A)
cb = Counter(B)

if ca.most_common(1)[0][1] >= 2 or cb.most_common(1)[0][1] >= 2:
    print(0)
    sys.exit(0)

A.sort()
B.sort()

import bisect


def index(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    return -1


for n in range(N * M, 0, -1):
    a = index(A, n)
    b = index(B, n)
    cntA = len(A) - bisect.bisect_right(A, n)
    cntB = len(B) - bisect.bisect_right(B, n)

    # 両方みつけた
    if a != -1 and b != -1:
        pass

    # Bの方だけ見つけた
    elif a == -1 and b != -1:
        ret *= cntA

    # Aの方だけ見つけた
    elif a != -1 and b == -1:
        ret *= cntB

    # 両方なかった
    else:
        ret *= (cntA * cntB - (N * M - n))
    ret = ret % MOD

print(ret)
