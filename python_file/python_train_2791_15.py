n,k=map(int,input().split())
h=list(map(int,input().split()))
d=[float('inf')]*n
d[0]=0
for i in range(n-1):
    for j in range(1,min(k+1,n-i)):
        d[i+j]=min(d[i+j],d[i]+abs(h[i+j]-h[i]))
print(d[-1])