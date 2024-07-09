n=int(input())
a=list(map(int,input().split()))
a.sort()
ans=[0]*n
i=0;j=n-1
while i<=n-1:
    ans[i]=a[j]
    j-=1;i+=2
i=1;j=0
while i<=n-1:
    ans[i]=a[j]
    i+=2;j+=1
print((n-1)//2)
print(*ans,sep=' ')