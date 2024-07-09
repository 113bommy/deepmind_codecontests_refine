M=10**6+1
f=lambda p: exit(print(['pairwise','setwise','not'][p]+' coprime'))
n,*l=map(int,open(0).read().split())
from math import *
g=l[0]
for x in l: g=gcd(g,x)
if g>1: f(2)
C=[0]*M
for x in l: C[x]=1
for i in range(2,M):
  if sum(C[j] for j in range(i,M,i))>1: f(1)
f(0)