k=int(input())
s=0
from math import gcd
for a in range(1,k+1):
  for b in range(1,k+1):
    for c in range(1,k+1):
      d=gcd(a,b)
      s+=gcd(d,c)
print(s)