import sys
N,M=map(int,input().split())
d=[set()for _ in range(N+1)]
def f(v,h,q):
 if d[v]&q:
  l,L=[],[]
  for x in h:
   l=[x]+l
   if x in d[v]:break
  while v!=x:
   for y in l:
    if v in d[y]:
     L,v=[v]+L,y
     break
  print("\n".join(str(x)for x in[len(L)+1,x]+L));sys.exit()
 for u in d[v]:f(u,[u]+h,q|{u})
for _ in range(M):a,b=map(int,input().split());d[a].add(b)
v=0;exec("v+=1;f(v,[v],{v});"*N)
print(-1)