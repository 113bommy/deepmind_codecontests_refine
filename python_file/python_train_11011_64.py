n,k,*a=map(int,open(0).read().split())
for _ in range(k):
  b=[0]*(n+1)
  for i,c in enumerate(a):
    b[max(0,i-c)]+=1
    b[min(n,c+i+1)]-=1
  for i in range(n):
    b[i+1]+=b[i]
  a=b[:-1]
  if a==[n]*n:
    print(*a)
    exit()
print(*a)