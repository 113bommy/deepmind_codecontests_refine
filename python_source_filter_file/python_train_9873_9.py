n,a,b=map(int,input().split())
ans=0
for i in range(1,n+1):
  if a<=sum(map(int,list(str(i))))<=b:
   ans=ans+1
print(ans)