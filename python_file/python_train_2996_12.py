import sys
sys.setrecursionlimit(10**8)
from collections import defaultdict,Counter
def saiki(cnts):
  hitomozi = []
  d = defaultdict(lambda: [])
  heads = defaultdict(lambda: 0)
  for s,c in cnts:
    if len(s)==1:
      hitomozi.append(s[0])
    else:
      for k,v in c.items():
        if v>0:
          heads[k] += 1
      t = s[-1]
      c[t] -= 1
      s.pop(-1)
      d[t].append([s,c])
  for h in hitomozi:
    ans[0] += heads[h]
  for v in d.values():
    if len(v)<=1:
      continue
    saiki(v)
  return 

N = int(input())
S = [list(input()) for _ in range(N)]
ans = [0]
cnts = []
for s in S:
  cnts.append([s,Counter(s)])
saiki(cnts)
print(ans[0])