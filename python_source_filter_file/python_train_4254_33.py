N,M,*ab=open(0).read().split()
from collections import*
C=Counter(ab)
print('YNeos'[any(v%2 for v in C.values())::2])