N=int(input())
ans=0
for i in range(N):
  if N%3!=0 and N%5!=0:
    ans+=i
print(ans)