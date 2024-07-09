import sys
input = sys.stdin.readline
 
class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
 
n,q = list(map(int,input().split()))
ball = list(map(int,input().split()))
 
h = Bit(n+1)

L = {}
jump = {}
on = set()

for i,b in enumerate(ball):
  if b not in L:
    h.add(i+1,1)
    on.add(i+1)
  if b in L:
    jump[L[b]]=i+1
  L[b] = i+1

Q = []
 
for _ in range(q):
  l,r = list(map(int,input().split()))
  Q.append((l,r))
  
LOO = list(Q)
Q.sort(key=lambda x:x[0])

c = 1
ans = {}

for l,r in Q:
  for i in range(c,l):
    if i in on:
      on.remove(i)
      h.add(i,-1)
      if i in jump:
        dest = jump[i]
        h.add(dest,1)
        on.add(dest)

  tmp = h.sum(r)- h.sum(l-1)
  ans[(l,r)] = tmp
  c = l

p = []
for q in LOO:
  p.append(ans[q])
  
print(*p, sep="\n")