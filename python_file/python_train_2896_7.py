n,k=map(int,input().split())
a=list(map(int,input().split()))
b=[]
for i in range(n):
    for j in range(i+1,n+1):
        s=sum(a[i:j])
        b.append(s)

x=0
for i in reversed(range(41)):
    cnt=0
    for j in b:
        if (x+2**i) & j ==(x+2**i):
            cnt+=1
    if cnt>=k:
        x+=2**i
print(x)