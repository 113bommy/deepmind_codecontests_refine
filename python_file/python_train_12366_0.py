h,*s=open(0)
h,w,k=map(int,h.split())
s=[list(map(int,t[:w]))for t in s]
m=9e9
for i in range(1<<h-1):
  t=[]
  b=v=l=0
  for j in range(h):
    if i>>j&1:
      t+=s[b:j+1],
      b=j+1
      l+=1
  t+=s[b:],
  l+=1
  c=[0]*l
  for i in range(w):
    f=g=0
    u=[]
    for j in range(l):
      d=sum(t[i]for t in t[j])
      u+=d,
      if d>k:
        g=1
        break
      c[j]+=d
      f|=c[j]>k
    else:
      v+=f
      if f:c=u
    if g:break
  else:m=min(m,v+l-1)
print(m)