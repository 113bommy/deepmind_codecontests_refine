n=int(input())
P=[int(i) for i in input().split()]
n_max=10**5
nn=n_max.bit_length()+1
BIT=[0]*(2**nn)
BIT.insert(0,0)
def bitsum(BIT,i):
  s=0
  while i>0:
    s+=BIT[i]
    i-=i&(-i)
  return s
def bitadd(BIT,i,x):
  while i<=2**nn:
    BIT[i]+=x
    i+=i&(-i)
  return BIT
def bitlb(BIT,s):
  if s<=0:
    return 0
  else:
    ret=0
    k=2**nn
    while k>0:
      if k+ret<=2**nn and BIT[k+ret]<s:
        s-=BIT[k+ret]
        ret+=k
      k//=2
    return ret+1
D=dict()
for i in range(n):
  D[P[i]]=i+1
PP=sorted(P,reverse=True)
bitadd(BIT,D[PP[0]],1)
ans=0
for i in range(1,n):
  cur=D[PP[i]]
  bitadd(BIT,cur,1)
  tot=bitsum(BIT,cur)
  l2,l1,r1,r2=bitlb(BIT,tot-2),bitlb(BIT,tot-1),min(n+1,bitlb(BIT,tot+1)),min(n+1,bitlb(BIT,tot+2))
  add=PP[i]*((-l1+cur)*(r2-r1)+(l1-l2)*(r1-cur))
  ans+=add
print(ans)