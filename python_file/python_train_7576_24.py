from fractions import*
_,a=open(0)
*a,=map(int,a.split())
s=1
for t in a:s*=t//gcd(s,t)
print(sum(s//i for i in a)%(10**9+7))