n,k=map(int,input().split())
f=3*n
if k==n or k==1:
    f=f
else:
    f=f+min(k-1,n-k)
print(f)
