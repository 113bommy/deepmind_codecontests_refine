from fraction import gcd
from functools import reduce
input()
print(reduce(gcd,list(map(int,input().split()))))