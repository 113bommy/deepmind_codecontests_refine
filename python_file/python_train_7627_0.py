from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop,heapify
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline

from itertools import accumulate
from functools import lru_cache

M = mod = 10 ** 9 + 7
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split()]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n')]
def li3():return [int(i) for i in input().rstrip('\n')]


graph = defaultdict(dict)

n, m = li()
l = []
for j in range(m):
    u, v, d = li()
    l.append([u, v, d])

l.sort(key = lambda x:x[-1])


def check(weight):
    airports = set()
    factoris = set()

    for i in l:
        if i[-1] <= weight:
            airports.add(i[0])
            factoris.add(i[1])
        else:break
    # print(weight, airports, factoris)
    return 1 if len(factoris) == len(airports) and len(factoris) == n else 0


low = 1
high = 10 ** 9

ans = 10 ** 10

while low <= high:
    mid = (low + high) >> 1
    if check(mid):
        ans = min(ans, mid)
        high = mid - 1
    else:low = mid + 1

if ans == 10 ** 10:
    print(-1)
    exit()
print(ans)