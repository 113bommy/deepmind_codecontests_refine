import re
import sys
exit=sys.exit
from bisect import bisect_left as bsl,bisect_right as bsr
from collections import Counter,defaultdict as ddict,deque
from functools import lru_cache
cache=lru_cache(None)
from heapq import *
from itertools import *
from math import inf
from pprint import pprint as pp
enum=enumerate
ri=lambda:int(rln())
ris=lambda:list(map(int,rfs()))
rln=sys.stdin.readline
rl=lambda:rln().rstrip('\n')
rfs=lambda:rln().split()
cat=''.join
catn='\n'.join
mod=1000000007
d4=[(0,-1),(1,0),(0,1),(-1,0)]
d8=[(-1,-1),(0,-1),(1,-1),(-1,0),(1,0),(-1,1),(0,1),(1,1)]
########################################################################

a={*'AHIMNOoTUVvWwXxY'}
b=dict('bd db pq qp'.split())

def solve(s):
  n=len(s)
  if n%2 and s[n//2] not in a:
    return 0
  for i in range(n//2):
    if s[i]==s[~i]:
      if s[i] not in a:
        return 0
    else:
      if b.get(s[i],'')!=s[~i]:
        return 0
  return 1

s=rl()
if solve(s):
  print('TAK')
else:
  print('NIE')
