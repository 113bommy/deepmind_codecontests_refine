from collections import deque

H, W, K = map(int, input().split())
A = [input() for h in range(H)]

for h in range(H):
  for w in range(W):
    if A[h][w] == 'S':
      sx, sy = h, w

INF = 1000
dist = [[INF for w in range(W)] for h in range(H)]
dist[sx][sy] = 0


dxy = [[1, 0], [0, 1], [-1, 0], [0, -1]]
start = []
d = deque([[sx, sy]])
while d:
  x, y = d.popleft()
  for dx, dy in dxy:
    xx = x + dx; yy = y + dy
    if 0<=xx<H and 0<=yy<W and dist[xx][yy]==INF:
      if A[xx][yy] == '.':
        dist[xx][yy] = dist[x][y] + 1
        d.append([xx, yy])
        if dist[xx][yy] <= K:
          start.append([xx, yy])

ans = min(-(-(H-1-sx)//K)+1, -(-sx//K)+1, -(-(W-1-sy)//K)+1, -(-sy//K)+1)
for x, y in start:
  ans = min(ans, -(-(W-1 - y)//K) + 1) # 右
  ans = min(ans, -(-y//K) + 1) # 左
  ans = min(ans, -(-(H-1 - x)//K) + 1) # 下
  ans = min(ans, -(-x//K) + 1) # 上

print(ans)