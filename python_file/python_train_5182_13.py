N,K=map(int,input().split())
P=list(map(int,input().split()))
P=[i-1 for i in P]
C=list(map(int,input().split()))
import math
ans=-10**18
for i in range(N):
  x=i
  tot=0
  cycle=[]
  while True:
    x=P[x]
    cycle.append(C[x])
    tot+=C[x]
    if x==i:
      break
  L=len(cycle)
  t=0
  for i in range(L):
    t+=cycle[i]
    if i+1>K:
      break
    now=t
    if tot>0:
      e=(K-i-1)//L
      now+=tot*e
    ans=max(ans,now)

print(ans)