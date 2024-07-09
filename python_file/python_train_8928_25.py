import collections

h,w,k=map(int,input().split())
sy,sx,gy,gx=map(int,input().split())
sy,sx,gy,gx=sy-1,sx-1,gy-1,gx-1
board=[input() for _ in range(h)]
q=collections.deque()
q.append((sx,sy))
checked=[[0]*w for _ in range(h)]
checked[sy][sx]=1
cost=[[10**18]*w for _ in range(h)]
cost[sy][sx]=0
dx=[1,0,-1,0]
dy=[0,1,0,-1]
while len(q)!=0:
  x,y=q.popleft()
  c=cost[y][x]
  for i in range(4):
    for j in range(1,k+1):
      if x+j*dx[i]<0 or w<=x+j*dx[i] or y+j*dy[i]<0 or h<=y+j*dy[i]:
        break
      if board[y+j*dy[i]][x+j*dx[i]]=='@':
        break
      if cost[y+j*dy[i]][x+j*dx[i]]<=c:
        break
      if cost[y+j*dy[i]][x+j*dx[i]]>c+1:
        q.append((x+j*dx[i],y+j*dy[i]))
        cost[y+j*dy[i]][x+j*dx[i]]=c+1
if cost[gy][gx]==10**18:
  print(-1)
else:
  print(cost[gy][gx])