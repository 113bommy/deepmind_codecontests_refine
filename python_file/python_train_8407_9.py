def f(i,x):
  while i<=n:
    b[i]+=x
    i+=i&-i
def g(i):
  s=0
  while i:
    s+=b[i]
    i-=i&-i
  return s
(n,q),a,*t=[map(int,t.split())for t in open(0)]
b=[0]*-~n
*map(f,range(1,n+1),a),
for q,l,r in t:
  if q:print(g(r)-g(l))
  else:f(l+1,r)