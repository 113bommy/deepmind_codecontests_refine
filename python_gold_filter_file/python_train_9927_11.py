import sys
from math import log2,floor,ceil,sqrt,gcd
import bisect
# from collections import deque
# sys.setrecursionlimit(7*10**4)

Ri = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()
 
def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
INF = 10 ** 18
MOD =  1000000007
flag  = False


n = int(ri())
a = Ri()

b = sorted(a)
cnt = 0
for i in range(n):
    if a[i] != b[i]:
        cnt+=1
if cnt >2 : 
    NO()
else:
    YES()