n=int(input())
a=list(map(int,input()))
t=1
p=a[0]
m=0
for i in a:
  if(p==i):
    continue
  if(m>0):
    if(i<p):
      t+=1
      m=0
  elif(m<0):
    if(i>p):
      t+=1
      m=0
  else:
    if(i>p):
      m=1
    elif(i<p):
      m=-1
  p=i
print(t)