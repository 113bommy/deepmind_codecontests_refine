n,k=map(int,input().split())
a=list(map(int,input().split()))

for _ in range(k):
    b=[0]*n
    for i in range(n):
        b[max(0,i-a[i])]+=1
        if i+a[i]<n-1:
            b[i+a[i]+1]-=1    
    f=0
    tmp=0
    for i in range(n):
        tmp+=b[i]
        a[i]=tmp
        if tmp!=n:
            f=1
    if f==0:
        break
print(*a)
