import bisect,sys
from itertools import *
n=range(50001);a=list(n);a[1]=0
for i in range(2,224):a[i*2::i]=[0]*len(a[i*2::i])
for x in map(int,sys.stdin):
 if x:y=x//2+1;print(sum(1 for d in compress(n[:y],a[:y])if a[x-d]))
