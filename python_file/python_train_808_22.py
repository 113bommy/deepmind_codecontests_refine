n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
ans=0
for i in range(60):
  o=0
  x=1<<i
  for j in a:
    if j&x:o+=1
  ans+=x*o*(n-o)
  ans%=mod
print(ans)