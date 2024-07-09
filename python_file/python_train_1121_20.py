import sys
from collections import deque

readline = sys.stdin.readline
readall = sys.stdin.read
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prn = lambda x: print(*x, sep='\n')

def solve():
  n, m = nm()
  ver = [tuple(nm()) for _ in range(n)]
  hor = [tuple(nm()) for _ in range(m)]
  xli = [0]*(2*n+m+1)
  yli = [0]*(n+2*m+1)
  for i, (a, b, c) in enumerate(ver):
    xli[i*2] = a
    xli[i*2+1] = b
    yli[i] = c
  for i, (a, b, c) in enumerate(hor):
    xli[2*n + i] = a
    yli[n + 2*i] = b
    yli[n + 2*i + 1] = c
  xli = sorted(set(xli))
  yli = sorted(set(yli))
  xdic = {x:i for i, x in enumerate(xli)}
  ydic = {x:i for i, x in enumerate(yli)}
  H = len(yli)*2 + 1
  W = len(xli)*2 + 1
  G = [[0]*W for _ in range(H)]
  for a, b, c in ver:
    a = xdic[a]; b = xdic[b]
    c = ydic[c]
    if a > b:
      a, b = b, a
    for i in range(2*a+1, 2*b+2):
      G[2*c+1][i] = 1
  for a, b, c in hor:
    a = xdic[a]
    b = ydic[b]; c = ydic[c]
    if b > c:
      b, c = c, b
    for i in range(2*b+1, 2*c+2):
      G[i][2*a+1] = 1
  # print(xli)
  # print(yli)
  # prn(G)
  q = deque()
  sx = xdic[0]*2+1; sy = ydic[0]*2+1
  G[sy-1][sx-1] = 2
  q.append((sy-1, sx-1))
  ans = 0
  while q:
    y, x = q.popleft()
    for ny, nx in ((y+2, x), (y-2, x), (y, x+2), (y, x-2)):
      if 0 <= ny < H and 0 <= nx < W and G[ny][nx] == 0 and G[(ny+y)//2][(nx+x)//2] != 1:
        G[ny][nx] = 2
        q.append((ny, nx))

  for ny in range(H):
    for nx in range(W):
      if G[ny][nx] > 1:
        if ny == 0 or ny == H-1 or nx == 0 or nx == W-1:
          print('INF')
          return
        if ny % 2 == nx % 2 == 0:
          ans += (yli[ny//2] - yli[ny//2-1]) * (xli[nx//2] - xli[nx//2-1])
  print(ans)
  return

solve()
