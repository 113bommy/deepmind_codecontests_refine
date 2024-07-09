N,x=map(int,input().split())
a=[int(i) for i in input().split()]
b=[[0 for k in range(N)] for i in range(N)]
for k in range(N):
    for i in range(N):
        if k==0:
            b[i][k]=a[i]
        else:
            b[i][k]=min([b[i][k-1],a[i-k]])
ans=sum(a)
for k in range(N):
    tmp=k*x
    for i in range(N):
        tmp+=b[i][k]
    if tmp<ans:
        ans=tmp
print(ans)
