n=int(input())
ans=0
for i in range(n):
  x,u=input().split()
  x=float(x)
  if u=="JPY":
    ans+=x
  else:
    ans+=3800*x
print(int(ans))