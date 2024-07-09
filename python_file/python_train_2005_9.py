import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
from fractions import Fraction
#sys.setrecursionlimit(100000)
INF = float('inf')
mod = int(1e9)+7


for t in range(int(data())):
    n=int(data())
    a=data()
    b=data()
    ind=n-1
    ans=[]
    for i in range(n):
        if a[i]==b[i]:
            continue
        ans.append(i+1)
        ans.append(1)
        ans.append(i+1)
    print(str(len(ans))+' '+' '.join(map(str,ans)))






