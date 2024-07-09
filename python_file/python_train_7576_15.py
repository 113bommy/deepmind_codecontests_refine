from fractions import gcd
def lcm(a,b):
    return (a*b)//gcd(a,b)
input()
a=[int(i) for i in input().split()]
l=a[0]
for i in a:
    l=lcm(i,l)
s=0
for i in a:
    s+=(l//i)
print(s%1000000007)