N=int(input())
ans=0
for i in range (N+1):
  if i%3!=0 and i%5!=0:
    ans+=1
print(ans)