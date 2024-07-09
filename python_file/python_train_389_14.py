n=int(input())
l=[*map(int,input().split())]
f=lambda p: exit(print(['pairwise','setwise','not'][p]+' coprime'))
from math import *
g=l[0]
for x in l: g=gcd(g,x)
if g>1: f(2)
from collections import *
C=Counter()
b=0
for x in l:
  if x%2<1:
    if C[2]: f(1)
    C[2]=1
  while x%2<1: x//=2
  for i in range(3,int(x**0.5)+1,2):
    if x%i<1:
      if C[i]: f(1)
      C[i]=1
    while x%i<1: x//=i
    if x<2: break
  if x>1:
    if C[x]: f(1)
    C[x]=1
f(0)