from collections import deque
H, W, K = map(int, input().split())
sx, sy, gx, gy = map(int, input().split())
sx -= 1
sy -= 1
gx -= 1
gy -= 1
grid = [input() for _ in range(H)]


def inside(r, c):
    return 0 <= r < H and 0 <= c < W and grid[r][c] != '@'


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
INF = 10**9
dist = [[INF]*W for _ in range(H)]
que = deque()
que.append([sx, sy])
dist[sx][sy] = 0
while que:
    [x, y] = que.popleft()
    for k in range(4):
        for d in range(1, K+1):
            nx = x + d*dx[k]
            ny = y + d*dy[k]
            if not inside(nx, ny) or dist[nx][ny] <= dist[x][y]:
                break
#             if not inside(nx, ny):
#                 break
#             if dist[nx][ny] <= dist[x][y]:
#                 break
            if dist[nx][ny] == INF:
                dist[nx][ny] = dist[x][y] + 1
                que.append([nx, ny])
if dist[gx][gy] == INF:
    print(-1)
else:
    print(dist[gx][gy])
