(n,q),*t=[map(int,t.split())for t in open(0)]
s=[0]
d=s*n
f=s+[1]*n
e=[[]for _ in d]
for a,b in t[:-q]:e[a-1]+=b-1,;e[b-1]+=a-1,
for p,x in t[-q:]:d[p-1]+=x
while s:
 v=s.pop()
 for w in e[v]:
  if f[w]:f[w]=0;d[w]+=d[v];s+=w,
print(*d)