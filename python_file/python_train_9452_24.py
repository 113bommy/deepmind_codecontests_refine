import sys
input = sys.stdin.readline
n,m,p=map(int,input().split())
edge = [[] for i in range(m)]
for i in range(m):
  a,b,c=map(int,input().split())
  edge[i]=[a-1,b-1,-c+p]
d=[float("inf")]*n
d[0]=0

for _ in range(n):
  for i in range(m):
    e0,e1,e2=edge[i]
    d[e1]=min(d[e1],d[e0]+e2)
ans1=d[-1]
for _ in range(n):
  for i in range(m):
    e0,e1,e2=edge[i]
    if d[e1]>d[e0]+e2:
      d[e1]=-float("inf")
ans2=d[-1]
print(-1 if ans1!=ans2 else max(0,-ans1))
