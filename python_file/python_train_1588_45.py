#import numpy as np
import sys, math
from itertools import permutations, combinations
from collections import defaultdict, Counter, deque
from math import factorial#, gcd
from bisect import bisect_left #bisect_left(list, value)
sys.setrecursionlimit(10**7)
enu = enumerate
MOD = 10**9+7
def input(): return sys.stdin.readline()[:-1]
pl = lambda x: print(*x, sep='\n')

from decimal import Decimal, getcontext
getcontext().prec = 1000

def solve():
    N = int(input())
    cosv = Decimal(math.cos(
        math.radians(180*(2*N-2)/(4*N))
    ))
    x = 1/(2*cosv)
    res = 2*x * Decimal(math.cos(math.radians(90/N)))
    res = float(res)
    print(res)
    return

T = int(input())
for t in range(T):
    solve()
