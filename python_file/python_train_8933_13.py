n,a,b,k=map(int,input().split())
mod=998244353
f=[1]
for i in range(n):f+=[f[-1]*(i+1)%mod]
def comb(a,b):return f[a]*pow(f[b],mod-2,mod)*pow(f[a-b],mod-2,mod)%mod
ans=0
for ac in range(k//a+1):
  asum=ac*a
  if (k-asum)%b:continue
  bc=(k-asum)//b
  if max(ac,bc)>n:continue
  ans=(ans+comb(n,ac)*comb(n,bc))%mod
print(ans)