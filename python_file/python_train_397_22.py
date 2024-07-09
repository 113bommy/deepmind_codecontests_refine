from collections import deque
h,w,k = map(int, input().split())
g = [list(input()) for _ in range(h)]
ans = h*w
for i in range(h):
  if 'S' in g[i]:
    sx = g[i].index('S')
    sy = i
    break
g[sy][sx] = 0
q = deque()
q.append(sy*w+sx)
while q:
  v = q.popleft()
  y,x = v//w, v%w
  cur = min((y-1)//k, (x-1)//k, (h-y-2)//k, (w-x-2)//k) + 2
  if ans > cur:
    ans = cur
  if g[y][x] < k:
    for dx,dy in ((0,1),(1,0),(0,-1),(-1,0)):
      nx = x+dx; ny = y+dy
      if 0 <= nx < w and 0 <= ny < h and g[ny][nx] == '.':
        g[ny][nx] = g[y][x] + 1
        q.append(ny*w+nx)
print(ans)