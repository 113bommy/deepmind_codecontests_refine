from collections import deque
h,w = map(int, input().split())
a = [list(input()) for _ in range(h)]
d = [(0,1),(1,0),(0,-1),(-1,0)]
q = deque()
cnt = h*w
t = 0
for i in range(h):
  for j in range(w):
    if a[i][j] == "#":
      q.append((i,j))
      a[i][j] = 0
      cnt -= 1
while cnt:
  y,x = q.popleft()
  for dx,dy in d:
    if 0 <= x+dx < w and 0 <= y+dy < h and a[y+dy][x+dx] == ".":
      a[y+dy][x+dx] = a[y][x] + 1
      cnt -= 1
      q.append((y+dy,x+dx)) 
for i in range(h):
  m = max(a[i])
  t = max(t,m)
print(t)