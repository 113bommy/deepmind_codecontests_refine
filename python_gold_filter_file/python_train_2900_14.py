a=list(map(int,input().split()))
ans=min(a[0],a[3],a[4])
a[0]-=ans
a[3]-=ans
a[4]-=ans
ans*=3
if(ans>0 and (a[0]%2+a[3]%2+a[4]%2==2)):
  ans+=1
ans+=(a[0]//2*2)+(a[3]//2*2)+(a[4]//2*2)+a[1]
print(ans)
