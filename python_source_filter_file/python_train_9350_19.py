n,k=map(int,input().split())
x=list(map(int,input().split()))
ans=2*(10**8)+1
for i in range(n-k+1):
    temp=x[i+k-1]-x[i]+min(abs(x[i]),abs(x[i+k-1]))
    if temp<ans: ans=temp
print(ans)