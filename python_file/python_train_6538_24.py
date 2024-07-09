h,w=map(int,input().split())
s=set()
a=[]
from collections import deque
q=deque([])
for i in range(h):
    tmp=list(input())
    a.append(tmp)
    for j in range(w):
        if tmp[j]=="#":
            q.append((i,j,0))

ans=0
ll=[[0,1],[0,-1],[1,0],[-1,0]]
while q:
    x,y,v=q.popleft()
    ans=max(ans,v)
    for i,j in ll:
        if 0<=x+i<h and 0<=y+j<w and a[i+x][j+y]==".":
            a[i+x][j+y]="#"
            q.append((i+x,j+y,v+1))

print(ans)



