class Bit:
  def __init__(self,n):
    self.bl = n.bit_length()
    self.size = n
    self.tree = [0]*(n+1)
 
  def sum(self,i):
    s = 0
    while i > 0:
      s += self.tree[i]
      i -= i & -i
    return s

  def add(self,i,x):
    while i <= self.size:
      self.tree[i] += x
      i += i & -i

import sys
input = sys.stdin.readline
from collections import defaultdict
n,q = map(int,input().split())
a = list(map(int,input().split()))
lr = [tuple(map(int,input().split()))+(i,) for i in range(q)]
ans = [0]*q
lr.sort(key = lambda x:x[1])
bit = Bit(n+2)
dc = defaultdict(int)
cnt = 0
for L,R,p in lr:
  L -= 1
  for i in range(cnt,R):
    if dc[a[i]]:
      l = dc[a[i]]-1
      r = i
      bit.add(l+2,1)
      bit.add(r+2,-1)
    else:
      bit.add(1,1)
      bit.add(i+2,-1)
    dc[a[i]] = i+1
  ans[p] = bit.sum(L+1)
  cnt = R
print(*ans,sep="\n")