n=int(input())
ans=0
for i in range(1,n+1):
  if len(str(n))%2==1:ans+=1
print(ans)