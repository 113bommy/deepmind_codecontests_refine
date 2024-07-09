r, g, b, n = map(int, input().split())
ans=0
for i in range(n//r+1):
    for j in range(n-r*i+1):
        p=n-(r*i+g*j)
        if p>=0 and p%b==0:
            ans+=1
print(ans)