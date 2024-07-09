n,k,*a=map(int,open(0).read().split())

from fractions import gcd


G=a[0]
for i in a:
    G=gcd(G,i)
    
A=max(a)
if k>A:
    print("IMPOSSIBLE")
    exit()
    
while A>0:
    if k==A:
        print("POSSIBLE")
        exit()
    A-=G
print("IMPOSSIBLE")