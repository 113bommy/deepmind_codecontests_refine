from collections import defaultdict
from bisect import *
def solve():
  ans = float('inf')
  N = int(input())
  L_y = defaultdict(lambda: [-float('inf'),float('inf')])
  R_y = defaultdict(lambda: [-float('inf'),float('inf')])
  U_x = defaultdict(lambda: [-float('inf'),float('inf')])
  D_x = defaultdict(lambda: [-float('inf'),float('inf')])
  R_xpy = defaultdict(lambda: [-float('inf'),float('inf')])
  R_y_x = defaultdict(lambda: [-float('inf'),float('inf')])
  L_xpy = defaultdict(lambda: [-float('inf'),float('inf')])
  L_y_x = defaultdict(lambda: [-float('inf'),float('inf')])
  U_xpy = defaultdict(lambda: [-float('inf'),float('inf')])
  U_y_x = defaultdict(lambda: [-float('inf'),float('inf')])
  D_xpy = defaultdict(lambda: [-float('inf'),float('inf')])
  D_y_x = defaultdict(lambda: [-float('inf'),float('inf')])
  for i in range(N):
    x,y,u = input().split()
    x,y = int(x),int(y)
    if u=='D':
      insort(D_x[x],y)
      insort(D_xpy[x+y],x)
      insort(D_y_x[y-x],x)
    if u=='U':
      insort(U_x[x],y)
      insort(U_xpy[x+y],x)
      insort(U_y_x[y-x],x)
    if u=='L':
      insort(L_y[y],x)
      insort(L_xpy[x+y],x)
      insort(L_y_x[y-x],x)
    if u=='R':
      insort(R_y[y],x)
      insort(R_xpy[x+y],x)
      insort(R_y_x[y-x],x)
  for k,v in R_y.items():
    for zahyou in v[1:-1]:
      ind = bisect_right(L_y[k],zahyou)
      dis = L_y[k][ind]-zahyou
      ans = min(ans,dis)
  for k,v in D_x.items():
    for zahyou in v[1:-1]:
      ind = bisect_right(U_x[k],zahyou)
      dis = zahyou-U_x[k][ind-1]
      ans = min(ans,dis)
  for k,v in L_y_x.items():
    for zahyou in v[1:-1]:
      ind = bisect_right(U_y_x[k],zahyou)
      dis = zahyou-U_y_x[k][ind-1]
      dis *= 2
      ans = min(ans,dis)
  for k,v in R_xpy.items():
    for zahyou in v[1:-1]:
      ind = bisect_right(U_xpy[k],zahyou)
      dis = U_xpy[k][ind]-zahyou
      dis *= 2
      ans = min(ans,dis)
  for k,v in L_xpy.items():
    for zahyou in v[1:-1]:
      ind = bisect_right(D_xpy[k],zahyou)
      dis = zahyou-D_xpy[k][ind-1]
      dis *= 2
      ans = min(ans,dis)
  for k,v in R_y_x.items():
    for zahyou in v[1:-1]:
      ind = bisect_right(D_y_x[k],zahyou)
      dis = D_y_x[k][ind]-zahyou
      dis *= 2
      ans = min(ans,dis)
  ans *= 5
  return ans if ans<float('inf') else 'SAFE'
print(solve())