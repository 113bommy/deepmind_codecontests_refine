r,g,b,n=map(int,input().split())

cnt=0
for i in range(n+1):
    for j in range(n+1):
        if (n-r*i-g*j)>=0 and (n-r*i-g*j)%b==0:
            cnt+=1
print(cnt)