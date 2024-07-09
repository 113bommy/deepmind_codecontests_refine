l,r=map(int,input().split())
m,ans=2019,2018
r=min(r,l+2019*2)
for i in range(l,r+1):
  for j in range(i+1,r+1):
    i%=m
    j%=m
    ans=min(ans,(i*j)%m)
print(ans)
