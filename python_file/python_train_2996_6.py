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
    if len(v)==2:
      s1,c1 = v[0]
      s2,c2 = v[1]
      l1,l2 = len(s1),len(s2)
      if l1==1:
        if l2>1 and c2[s1[0]]>0:
          ans[0] += 1
        continue
      else:
        if l2==1:
          if c1[s2[0]]>0:
            ans[0] += 1
          continue
        elif (l1>l2 and s2==s1[l1-l2:]) or (l2>l1 and s1==s2[l2-l1:]):
          ans[0] += 1
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