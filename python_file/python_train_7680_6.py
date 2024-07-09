n,k=map(int,input().split())
m=10**9+7
p=1
for i in range(1,n+1):p=(p*(2*n-i)*pow(i,m-2,m))%m
if k>=n:
    print(p)
else:
    c,d=1,1
    for i in range(1,k+1):c=(c*(n-i)*pow(i,m-2,m))%m
    for i in range(1,k+1):d=(d*(n-i+1)*pow(i,m-2,m))%m
    for i in range(k+1,n):
        c=(c*(n-i)*pow(i,m-2,m))%m
        d=(d*(n-i+1)*pow(i,m-2,m))%m
        p=(p-c*d)%m
    print(p)