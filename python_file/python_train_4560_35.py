import math
n,k=map(int,input().split())
a=list(map(int,input().split()))
f=list(map(int,input().split()))
a=sorted(a)
f=sorted(f,reverse=True)
l=-1
r=2*10**12+1
while l+1<r:
  c=(l+r)//2
  s=0
  for i in range(n):
    m=max(0,math.ceil((a[i]*f[i]-c)/f[i]))
    s=s+m
  if s>k:
  	l=c
  else:
    r=c
print(r)