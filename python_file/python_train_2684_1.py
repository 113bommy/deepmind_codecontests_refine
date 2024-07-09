mod=998244353
n,m,k=map(int,input().split())
fcl=[1]*(n+1)
for i in range(1,n+1):
  fcl[i]=(fcl[i-1]*i)%mod
def comb(x,y,p):
  return ((fcl[x]*pow(fcl[y],p-2,p))%p*pow(fcl[x-y],p-2,p))%p
ans=0
for i in range(k+1):
  ans+=m*pow(m-1,n-1-i,mod)*comb(n-1,i,mod)
  ans%=mod
print(ans)