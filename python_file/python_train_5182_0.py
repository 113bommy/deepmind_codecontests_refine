n,k=map(int,input().split())
p=list(map(int,input().split()))
c=list(map(int,input().split()))
for i in range(n):
    p[i]-=1
ans=max(c)
for i in range(n):
    f=i
    r=0
    l=[]
    while True:
        f=p[f]
        l.append(c[f])
        r+=c[f]
        if f==i:
            break
    t=0
    for j in range(len(l)):
        t+=l[j]
        if j+1>k:
            break
        ret=t
        if r>0:
            e=(k-j-1)//len(l)
            ret+=r*e
        ans=max(ans,ret)
print(ans)
