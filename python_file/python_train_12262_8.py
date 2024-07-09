import math as mt
import itertools as iters

K = int(input())
A = 0
for a,b,c in iters.product(range(1,K+1),repeat=3):
    A += mt.gcd(a,mt.gcd(b,c))
print(A)