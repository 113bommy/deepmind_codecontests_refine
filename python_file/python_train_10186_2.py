import itertools
n,m,r=map(int,input().split());R=min(r,8)
d = [[10**12for i in range(n)]for j in range(n)]
l=list(map(int,input().split()))
for i in range(r):
  l[i]-=1
for i in range(m):
  a,b,c=map(int,input().split())
  d[a-1][b-1]=d[b-1][a-1] = c
for k in range(n):
  for i in range(n):
    for j in range(n):
      d[i][j]=min(d[i][j], d[i][k]+d[k][j])
#print(d)
ans=10**12
for v in itertools.permutations(l, R):
  cnt=0
  for i in range(1,R):
    cnt+=d[v[i-1]][v[i]]
  ans=min(ans,cnt)
print(ans)