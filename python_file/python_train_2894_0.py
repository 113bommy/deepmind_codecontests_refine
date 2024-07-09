import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline
n,q=map(int,input().split())
c=[[] for _ in range(n)]
for _ in range(n-1):
  a,b=map(int,input().split())
  a,b=a-1,b-1
  c[a].append(b)
  c[b].append(a)
px=[0]*n
for I in range(q):
    p,x=map(int,input().split())
    px[p-1]+=x 
ans=[0]*n
def dfs(g,h=-1):
  ans[g]=ans[h]+px[g]
  for i in c[g]:
    if i==h:continue
    dfs(i,g)
dfs(0)
print(*ans)
