import sys
sys.setrecursionlimit(10**6)
e=enumerate
def dfs(v):
  d=sorted(map(dfs,t[v]))
  l=len(d)
  return max([0]+[l-i+d for i,d in e(d)])
n,*a=map(int,open(0))
t=[[]for _ in[0]+a]
for i,v in e(a,1):t[v-1]+=i,
print(dfs(0))