n,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
l=0
r=a[-1]
while r-l>1:
  cnt=0
  m=(l+r)//2
  #print("l,m,r",l,m,r)
  for i in a:
    cnt+=(i-1)//m
  if cnt<=k:
    r=m
  else:
    l=m
print(r)