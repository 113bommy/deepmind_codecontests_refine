from collections import deque

INF = 10**18

H, W, K = map(int, input().split())
x1, y1, x2, y2 = map(lambda x: int(x) - 1, input().split())
C = [input() for _ in range(H)]

queue = deque()
queue.append((x1, y1))

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

dist = [[INF for j in range(W)] for i in range(H)]
dist[x1][y1] = 0

while queue:
    x, y = queue.popleft()
    for i in range(4):
        for k in range(K):
            nx = x + (k + 1) * dx[i]
            ny = y + (k + 1) * dy[i]
            if not (0 <= nx < H and 0 <= ny < W):
                break
            if C[nx][ny] == '@':
                break
            if dist[nx][ny] <= dist[x][y]:
                break
            if dist[nx][ny] != INF:
                continue
            dist[nx][ny] = dist[x][y] + 1
            queue.append((nx, ny))

print(dist[x2][y2] if dist[x2][y2] != INF else -1)