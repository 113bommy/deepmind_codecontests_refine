from collections import defaultdict
import sys
# Binary Indexed Tree (Fenwick Tree)
class BIT():
    def __init__(self, n):
        '''
        n = 要素数
        要素の添字iは 0 <= i < n となる
        '''
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, i, value):
        '''i番目の要素にvalueを加算する O(logN)'''
        i = i + 1
        while i <= self.n:
            self.bit[i] += value
            i += i & -i

    def _sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def sum(self, l, r):
        '''区間[l, r)の和を求める O(logN)'''
        return self._sum(r) - self._sum(l)


input = sys.stdin.readline
N, Q = map(int, input().split())
C = list(map(int, input().split()))
LR = [tuple(map(int, input().split())) for _ in range(Q)]
query = [[] for _ in range(N)]
for i, (l, r) in enumerate(LR):
    query[l-1].append((i, r-1))

hist = defaultdict(lambda: -1)
nx = [-1] * N
for i in range(N-1, -1, -1):
    nx[i] = hist[C[i]]
    hist[C[i]] = i

bit = BIT(N)
ans = [None]*Q
for l in range(N-1,-1,-1):
    if nx[l] != -1:
        bit.add(nx[l],-1)
    for i,r in query[l]:
        ans[i] = (r-l+1) + bit.sum(l,r+1)

print(*ans,sep = '\n')