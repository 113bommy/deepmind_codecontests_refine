from collections import deque
h,w=map(int,input().split())
a=[input() for _ in range(h)]
inf=10**10
dist=[[inf if c=='.' else 0 for c in r] for r in a]
dq=deque()
for i in range(h):
    for j in range(w):
        if dist[i][j]==0:
            dq.append([i,j])
diff=[[1,0],[0,1],[-1,0],[0,-1]]
ans=0
while(dq):
    y,x=dq.popleft()
    for dy,dx in diff:
        y2=y+dy
        x2=x+dx
        if 0<=y2<h and 0<=x2<w and dist[y2][x2]>dist[y][x]+1:
            dq.append([y2,x2])
            dist[y2][x2]=dist[y][x]+1
            ans=max(ans,dist[y2][x2])
print(ans)