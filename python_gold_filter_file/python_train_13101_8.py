n,c,k=map(int,input().split())
o=sorted(int(input()) for _ in range(n))
cnt=0
l=0
r=0

while l<n:
  while r<n and o[r]<=o[l]+k and r-l+1<=c:
    r+=1
  cnt+=1
  l=r

print(cnt)