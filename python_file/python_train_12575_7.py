n,s=open(0)
n=int(n)
a=0
for i in range(n):
  t=0
  for v,w in zip(s,s[i:n]):
    t=-~t*(v==w)
    a=max(a,min(t,i))
print(a)