class Segtree:
    def __init__(self, original, func, element):
        self.n = len(original)
        self.element = element
        self.func = func
        self.N0 = 1 << (n-1).bit_length()
        self.seg = [element]*(self.N0 << 1)
        for i, j in enumerate(original, self.N0):
            self.seg[i] = j
        for i in range(self.N0-1, 0, -1):
            self.seg[i] = func(self.seg[2*i], self.seg[2*i+1])

    def get(self, i):
        return self.seg[i+self.N0]
        
    def update(self, i, x):
        i += self.N0
        self.seg[i] = x
        while i > 1:
            y = self.seg[i ^ 1]
            i >>= 1
            x = self.func(x, y)
            self.seg[i] = x
                
    def query(self, l, r):
        res = self.element
        l += self.N0
        r += self.N0
        while l < r:
            if r & 1:
                res = self.func(res, self.seg[r-1])
            if l & 1:
                res = self.func(res, self.seg[l])
                l += 1
            l >>= 1
            r >>= 1
     
        return res

import sys
input = sys.stdin.readline
read = sys.stdin.read
from itertools import accumulate

def compress(arr):
    *XS, = set(arr)
    XS.sort()
    d = {e: i for i, e in enumerate(XS)}
    return [d[e] for e in arr]

n, k = map(int, input().split())
if n == 1:
  print(int(int(input()) >= k))
  exit()
A = list(map(lambda x:int(x)-k, read().split()))
L = [0] + list(accumulate(A))
L = compress(L)
seg = Segtree([0]*(max(L)+1), lambda x, y:x+y, 0)
ans = 0
for l in L:
  ans += seg.query(0, l+1)
  t = seg.get(l)
  seg.update(l, t+1)
print(ans)