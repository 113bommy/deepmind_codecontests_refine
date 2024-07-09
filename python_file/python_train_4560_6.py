n,k=map(int,input().split())
A=sorted(list(map(int,input().split())))
F=sorted(list(map(int,input().split())),reverse=True)
ng=-1
ok=10**12+10
while ok-ng>1:
  mid=(ok+ng)//2
  a=0
  for i in range(n):
    a=a+max(0,A[i]-mid//F[i])
  if a>k:
    ng=mid
  else:
    ok=mid
print(ok)