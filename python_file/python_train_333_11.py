from collections import defaultdict
from math import floor

d = defaultdict(list)

n, k = map(int, input().split())
a = list(map(int, input().split()))

for i in a:
   c, tmp = 0, i
   while True:
      d[tmp].append(c)
      if tmp==0: break
      tmp = floor(tmp/2)
      c+=1

mn = 2*10**5
for ke in d: 
   ans = 0
   l = len(d[ke])
   if l<k: continue
   fin = sorted(d[ke])
   for i in range(k):
      ans+=fin[i]
   mn = min(mn, ans)

print(mn)

