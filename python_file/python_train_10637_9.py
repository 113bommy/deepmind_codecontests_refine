from sys import *
from math import *
mod=998244353
n=int(stdin.readline())
a=list(input().split())
b=[]
for i in range(n):
    s=list(map(int,a[i]))
    x=0
    for j in s:
        x*=10
        x+=j
        x%=mod
        x*=10
        x+=j
        x%=mod
    b.append(x)
ans=(sum(b)*n)%mod
print(ans)
