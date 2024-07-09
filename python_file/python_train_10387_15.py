import sys
input = lambda: sys.stdin.readline().rstrip()

n,q=map(int,input().split())
a=list(map(int,input().split()))

num = 2**(n-1).bit_length()
def segfunc(x, y): return max(x, y)
seg = [0]*(2*num-1)
for i in range(n):
  seg[i+num-1] = a[i]
for i in range(num-2, -1, -1):
  seg[i] = segfunc(seg[2*i+1], seg[2*i+2])
def update(i, x):
  i += num-1
  seg[i] = x
  while i:
    i = (i-1)//2
    seg[i] = segfunc(seg[i*2+1], seg[i*2+2])
def query(l, r):
  l += num-1
  r += num-2
  if l == r:
    return seg[l]
  s = seg[l]
  l += 1
  while r-l > 1:
    if ~l % 2:
      s = segfunc(seg[l], s)
    if r % 2:
      s = segfunc(seg[r], s)
      r -= 1
    l //= 2
    r = (r-1)//2
  if l == r:
    return segfunc(s, seg[l])
  return segfunc(s, segfunc(seg[l], seg[r]))

for _ in range(q):
  t,a,b=map(int,input().split())
  if t==1:
    update(a-1,b)
  if t==2:
    print(query(a-1,b))
  if t==3:
    ng=a-1
    ok=n+1
    while ng+1!=ok:
      mid=(ng+ok)//2
      if query(ng,mid)>=b:ok=mid
      else:ng=mid
    print(ok)