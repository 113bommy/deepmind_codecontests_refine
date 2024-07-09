MOD=10**9+7
def facinv(N):
    fac,finv,inv=[0]*(N+1),[0]*(N+1),[0]*(N+1)
    fac[0]=1;fac[1]=1;finv[0]=1;finv[1]=1;inv[1]=1
    for i in range(2,N+1):
        fac[i]=fac[i-1]*i%MOD
        inv[i]=MOD-inv[MOD%i]*(MOD//i)%MOD
        finv[i]=finv[i-1]*inv[i]%MOD
    return fac,finv,inv

def COM(n,r):
    if n<r or r<0:
        return 0
    else:
        return ((fac[n]*finv[r])%MOD*finv[n-r])%MOD
        
r1,c1,r2,c2=map(int,input().split())

fac,finv,inv=facinv(r2+c2+1)

ans=0

for i in range(r1,r2+1):
    ans=(ans+COM(c2+i+1,i+1)-COM(c1+i,i+1)+MOD)%MOD
print(ans)