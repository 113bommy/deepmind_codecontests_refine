n,k=map(int,input().split())
ans=-10000000000
for i in range(n):
    f,t=map(int,input().split())
    if t>k:
        ans=max(ans,f-(t-k))
    else:
        ans=max(ans,f)
print(ans)
    
    