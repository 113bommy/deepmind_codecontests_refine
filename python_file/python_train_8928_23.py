import sys
from collections import deque
h,w,k = map(int, sys.stdin.readline().rstrip("\n").split())
sx,sy,gx,gy = map(int, sys.stdin.readline().rstrip("\n").split())
sx,sy,gx,gy = sx-1,sy-1,gx-1,gy-1
labyrinth = [line.rstrip("\n") for line in sys.stdin]
INF = float('inf')
footprint = [ [[(INF,INF)]*4 for j in range(w)] for i in range(h) ]
m = [(-1, 0), (0, 1), (1, 0), (0, -1)]
q = deque()
for d in range(4):
    footprint[sx][sy][d] = (1,0)
    q.append((sx,sy,d,1,0))
while q:
    x, y, d, c, kk = q.popleft()
    for nd in range(4):
        if nd == d:
            mx,my = m[d]
            nkk = 1 if kk == k else kk + 1
            nc = c + 1 if kk == k else c
        else:
            mx,my = 0,0
            nkk = 0
            nc = c + 1
        nx = x + mx
        ny = y + my
        if 0 <= nx < h and 0 <= ny < w and labyrinth[nx][ny] == '.' and footprint[nx][ny][nd] > (nc, nkk):
            footprint[nx][ny][nd] = (nc, nkk)
            if nc == c:
                q.appendleft((nx, ny, nd, nc, nkk))
            else:
                q.append((nx, ny, nd, nc, nkk))
ans = INF
for d in range(4):
    ans = min(ans, footprint[gx][gy][d][0])
ans = -1 if ans == INF else ans
print(ans)