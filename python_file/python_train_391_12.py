import sys
sys.setrecursionlimit(10 ** 9)

N,u,v = map(int,input().split())
u -= 1
v -= 1
E = [set() for _ in range(N)]
for _ in range(N-1):
  a,b = map(int,input().split())
  a -= 1
  b -= 1
  E[a].add(b)
  E[b].add(a)

DU = [-1 for _ in range(N)]  
DV = [-1 for _ in range(N)]
def dfs(p,c,D):
  D[p] = c
  for q in E[p]:
    if D[q] == -1:
      dfs(q,c+1,D)
dfs(u,0,DU)
dfs(v,0,DV)
#print(DU)
#print(DV)
mx = 0
for du,dv in zip(DU,DV):
  if du < dv:
    mx = max(dv,mx)
print(mx-1)