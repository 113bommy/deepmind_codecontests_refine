import itertools
n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(min(k,50)):
  imos=[0]*(n+1)
  for j in range(n):
    imos[max(j-a[j],0)]+=1
    imos[min(j+a[j]+1,n)]-=1
  a=list(itertools.accumulate(imos))
  if a[:n]==[n]*n:
    break
    
print(*a[:n]) 
