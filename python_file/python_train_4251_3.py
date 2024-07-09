n,m=map(int,input().split())

def c(n,m):
    import math
    if n-m<0:
        return 0
    return(math.factorial(n)//math.factorial(n-m)//math.factorial(m))

def factorize(n):
    fct=[]
    b,e=2,0
    while b*b<=n:
        while n%b==0:
            n=n//b
            e=e+1
        if e>0:
            fct.append((b,e))
        b,e=b+1,0
    if n>1:
        fct.append((n,1))
    return fct

l=factorize(m)
mod=10**9+7
ans=1
for i,j in l:
    ans*=c(j+n-1,j)
    ans=ans%mod

print(ans)