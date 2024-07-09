import collections
import sys
input=sys.stdin.readline

def calc():
  h,w,k=map(int,input().split())
  sy,sx,gy,gx=map(int,input().split())
  sy,sx,gy,gx=sy-1,sx-1,gy-1,gx-1
  board=[input() for _ in range(h)]
  q=collections.deque()
  q.append((sx,sy))
  checked=[[[0,0,0,0] for _ in range(w)] for _ in range(h)]
  checked[sy][sx][0]=1
  checked[sy][sx][1]=1
  checked[sy][sx][2]=1
  checked[sy][sx][3]=1
  cost=[[10**18]*w for _ in range(h)]
  cost[sy][sx]=0
  while len(q)!=0:
    x,y=q.popleft()
    c=cost[y][x]
    for i in range(1,k+1):
      if x+i<w and checked[y][x+i][0]==0 and board[y][x+i]=='.' and c<cost[y][x+i]:
        checked[y][x+i][0]=1
        cost[y][x+i]=c+1
        q.append((x+i,y))
      else:
        break
    for i in range(1,k+1):
      if x-i>=0 and checked[y][x-i][1]==0 and board[y][x-i]=='.' and c<cost[y][x-i]:
        checked[y][x-i][1]=1
        cost[y][x-i]=c+1
        q.append((x-i,y))
      else:
        break
    for i in range(1,k+1):
      if y+i<h and checked[y+i][x][2]==0 and board[y+i][x]=='.' and c<cost[y+i][x]:
        checked[y+i][x][2]=1
        cost[y+i][x]=c+1
        q.append((x,y+i))
      else:
        break
    for i in range(1,k+1):
      if y-i>=0 and checked[y-i][x][3]==0 and board[y-i][x]=='.' and c<cost[y-i][x]:
        checked[y-i][x][3]=1
        cost[y-i][x]=c+1
        q.append((x,y-i))
      else:
        break
  if cost[gy][gx]==10**18:
    print(-1)
  else:
    print(cost[gy][gx])
calc()