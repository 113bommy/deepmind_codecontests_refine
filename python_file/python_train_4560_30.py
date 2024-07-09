N,K=map(int,input().split())
A=sorted(map(int,input().split()))
F=sorted(map(int,input().split()),reverse=True)

l=-1
r=A[-1]*F[0]
while l+1<r:
  x=(l+r)//2
  cnt=0
  for i in range(N):
    cnt+=max(A[i]-x//F[i],0)
  if cnt<=K:
    r=x
  else:
    l=x
    
print(r)