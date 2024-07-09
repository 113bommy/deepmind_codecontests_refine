from collections import deque
H,W = map(int,input().split())
CH,CW = map(int,input().split())
DH,DW = map(int,input().split())
maze = [list(input()) for _ in range(H)]
 
def BFS(maze,s,g):
  q1 = deque([s])
  checked = []
  cost = [[-1]*W for _ in range(H)]
  m = 0
  while q1:
    h,w,n = q1.popleft()
    if cost[h][w]<0:
      cost[h][w] = n
      if (h,w)==g: return n
      dp = [(x-2,y-2) for x in range(5) for y in range(5) if (x-2)!=0 or (y-2)!=0]
      for dh,dw in dp:
        if 0<=h+dh<H and 0<=w+dw<W and maze[h+dh][w+dw]==".":
          if (dh,dw) in [(-1,0),(1,0),(0,-1),(0,1)]:
            q1.appendleft((h+dh,w+dw,n))
          else:
            q1.append((h+dh,w+dw,n+1))
  return cost[g[0]][g[1]]
print(BFS(maze,(CH-1,CW-1,0),(DH-1,DW-1)))