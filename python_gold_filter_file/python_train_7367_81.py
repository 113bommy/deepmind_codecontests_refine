l,r,d=map(int,input().split())
c=0
for x in range(l,r+1):
  if x%d==0:
    c=c+1
print(c)