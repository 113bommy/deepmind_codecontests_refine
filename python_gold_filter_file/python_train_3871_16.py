
n,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
j=0
r=n//2
cnt=1
ans=0
u=0
for i in range(r+1,n):
    value=cnt*(a[i]-a[i-1])
    if(value<k):
        k-=value
    elif(value==k):
        j=1
        ans=a[i]
        break
    else:
        ans=a[i-1]+k//cnt
        u=1
        break
    cnt+=1
if(j!=1 and u!=1):
    ans=a[n-1]+k//(n-r)
if(j==1):
    print(ans)
elif(u==1):
    print(ans)
else:
    print(ans)