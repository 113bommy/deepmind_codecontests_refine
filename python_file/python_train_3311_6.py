r,g,b,n=map(int,input().split())
a=0
for i in range(0,n+1,r):
    for j in range(0,n+1,g):
        k=n-i-j
        if k>=0 and not k%b:
            a+=1
print(a)