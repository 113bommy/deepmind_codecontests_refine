n=int(input())
a=input()
ans=0
s="xxx"
i=0
if(a=="xxx"):
  print(ans+1)
else:
  while((i+3)<n):
    #print(a)
    if(s==a[i:i+3]):
      a=a[:i+2]+a[i+3:]
      i=0
      ans+=1
    else:
      i+=1
  #print(a)
  print(ans)
