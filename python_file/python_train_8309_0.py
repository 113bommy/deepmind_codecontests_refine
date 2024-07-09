n,q,*t=map(int,open(0).read().split())
for v,w in zip(t[::2],t[1::2]):
  if n<2:
    print(min(v,w))
    continue
  s,t=set(),set()
  while v:
    s|={v}
    v=(v+n-2)//n
  while w:
    t|={w}
    w=(w+n-2)//n
  print(max(s&t))