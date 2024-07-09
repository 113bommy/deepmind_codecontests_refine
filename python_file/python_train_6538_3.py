from collections import deque
h,w=map(int,input().split())
a=[input() for _ in range(h)]
visited=[[-1]*w for _ in range(h)]
queue=deque()
for i in range(h):
  for j in range(w):
    if a[i][j]=='#':
      visited[i][j]=0
      queue.append([i,j])
while queue:
  y,x=queue.popleft()
  for j,k in ([1,0],[-1,0],[0,1],[0,-1]):
    n_y,n_x=y+j,x+k
    if 0<=n_y<h and 0<=n_x<w and a[n_y][n_x]=='.' and visited[n_y][n_x]<0:
      visited[n_y][n_x]=visited[y][x]+1
      queue.append([n_y,n_x])
ans=0
for l in visited:
  ans=max([ans]+l)
print(ans)