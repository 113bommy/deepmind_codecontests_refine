import queue
h,w=map(int,input().split())
a=[input() for _ in range(h)]
q=[]
dist=[[-1 for _ in range(w)]for _ in range(h)]
for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            q.append([i,j])
            dist[i][j]=0
q=queue.deque(q)
d=[[1,0],[0,1],[-1,0],[0,-1]]
while q:
    y,x=q.popleft()
    for dy,dx in d:
        ny,nx=y+dy,x+dx
        if 0<=ny and ny<h and 0<=nx and nx<w and dist[ny][nx]==-1:
            dist[ny][nx]=dist[y][x]+1
            q.append([ny,nx])
ans=0
for i in range(h):
    for j in range(w):
        ans=max(ans,dist[i][j])
print(ans)