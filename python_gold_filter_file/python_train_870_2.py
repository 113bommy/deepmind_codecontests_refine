n=int(input())
a=list(map(int,input().split()))
m=int(input())
for i in range(m):
    x,y=map(int,input().split())
    x=x-1
    if x==0:
        if len(a)>1:
            a[x+1]+=a[0]-y
        a[x]=0
    elif x==(n-1):
        if len(a)>1:
            a[x-1]+=y-1
        a[x]=0
    else:
        a[x-1]+=y-1
        a[x+1]+=a[x]-y
        a[x]=0
for i in range(n):
    print(a[i])