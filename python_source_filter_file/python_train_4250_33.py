a,b,c=map(int,input().split())
for i in range(101,1,-1):
  if a%i==0 and b%i==0:
    c-=1
  if c==0:
    print(i)
    break
