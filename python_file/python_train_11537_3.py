A,B,Q=map(int,input().split())
inf=1e50
s=[-inf]
for _ in range(A):
    s.append(int(input()))
s.append(inf)

t=[-inf]
for _ in range(B):
    t.append(int(input()))
t.append(inf)
from bisect import bisect

for _ in range(Q):
    x=int(input())
    i=bisect(s,x)
    j=bisect(t,x)
    
    sL=x-s[i-1]
    sR=s[i]-x
    
    tL=x-t[j-1]
    tR=t[j]-x
    print(min(max(sR,tR),max(sL,tL),sR+tL+min(sR,tL),sL+tR+min(sL,tR)))


