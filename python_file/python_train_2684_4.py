n,m,k=map(int,input().split())
ans=0
mod=998244353
f=[1]
for i in range(n):f+=[f[-1]*(i+1)%mod]
def comb(a,b):return f[a]*pow(f[b],mod-2,mod)*pow(f[a-b],mod-2,mod)%mod
for kk in range(k+1):
  anss=m*pow(m-1,n-1-kk,mod)%mod
  anss=anss*comb(n-1,kk)%mod
  ans=(ans+anss)%mod
print(ans)