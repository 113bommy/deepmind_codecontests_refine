n,k=map(int,input().split())
a=list(map(int,input().split()))

def imos(n,a):
  imos_l=[0]*n
  for i in range(n):
    l=max(i-a[i],0)
    r=min(i+a[i],n-1)
    imos_l[l]+=1
    if (r+1)!=n:
      imos_l[r+1]-=1

  b=[0]
  for i in range(1,n+1):
    b.append(imos_l[i-1]+b[i-1])
  return b[1:]

for i in range(k):
  na=imos(n,a)
  if na==a:
    break
  a=na

print(*a)