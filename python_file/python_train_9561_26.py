n,k=map(int,input().split())
x=[0]*n
y=[0]*n
for i in range(n):
    x[i],y[i]=map(int,input().split())
ans=float('inf')
for i1 in range(n):
    for i2 in range(i1+1,n):
        for j1 in range(n):
            for j2 in range(j1+1,n):
                a,b=sorted([x[i1],x[i2]])
                c,d=sorted([y[j1],y[j2]])
                cnt=0
                for i in range(n):
                    if a<=x[i]<=b and c<=y[i]<=d:
                        cnt+=1
                if cnt>=k:
                    ans=min(ans,(b-a)*(d-c))
print(ans)