from collections import deque
H, W = map(int, input().split())
C = []
Q = deque()
dist = [[-1]*W for i in range(H)]

for i in range(H):
  s = list(input())
  yxidx = [(i,x) for x,v in enumerate(s) if v == "#"]
  for (y, x) in yxidx:
    Q.append((y,x))
    dist[y][x] = 0
  C.append(s)
X = [1,0,-1,0]
Y = [0,-1,0,1]


while Q:
  y,x = Q.popleft()
  for i in range(4):
    nx = x + X[i]
    ny = y + Y[i]
    if (0 <= nx < W) and (0 <= ny < H) and (dist[ny][nx] == -1):
      dist[ny][nx] = dist[y][x] + 1
      Q.append((ny,nx))

ans = 0
for i in range(H):
  ans = max(ans,max(dist[i]))
print(ans)
