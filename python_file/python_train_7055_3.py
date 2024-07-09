n,m=map(int,input().split())
mod=10**9+7
f=[1]
for i in range(1,max(m,n)+1):f.append(f[i-1]*i%mod)
def comb(n,r):return f[n]*pow(f[r],mod-2,mod)*pow(f[n-r],mod-2,mod)%mod
def pern(n,r):return f[n]*pow(f[n-r],mod-2,mod)%mod
a=[0]*(n+1)
a[n]=1
for i in range(n-1,-1,-1):
    a[i]=(comb(n,n-i)*pern(m-i,n-i)-a[i+1])%mod
print(a[0]*pern(m,n)%mod)
