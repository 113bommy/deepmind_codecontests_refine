x=int(input())

ans=1

for i in range(2,x):
  a=i
  while a*i<=x:
    a*=i
  if ans<a:
    ans=a

print(ans)