from collections import deque

H, W, K = map(int, input().split())

move = [(1, 0), (-1, 0), (0, 1), (0, -1)]

G = [list(input()) for _ in range(H)]
check = [[-1] * (W) for _ in range(H)]

que = deque()

flag = False
for h in range(H):
    for w in range(W):
        if G[h][w] == 'S':
            que.append((h, w))
            flag = True
            break
    if flag:
        break

x_min = h
x_max = h

y_min = w
y_max = w

check[h][w] = 0
while que:
    tmp = que.popleft()
    
    x = tmp[0]
    y = tmp[1]
    
    now_ = check[x][y]
    if now_ == K:
        continue

    for dx, dy in move:
        nx = x + dx
        ny = y + dy
        if not (0 <= nx < H and 0 <= ny < W):
            continue
        if G[nx][ny] == '#':
            continue
        if check[nx][ny] == -1:
            check[nx][ny] = now_ + 1
            que.append((nx, ny))
            
            x_min = min(x_min, nx)
            x_max = max(x_max, nx)

            y_min = min(y_min, ny)
            y_max = max(y_max, ny)

ans = 10 ** 18
ans = min(ans, (x_min + K - 1) // K + 1)
ans = min(ans, (H - x_max - 1 + K - 1) // K + 1)
ans = min(ans, (y_min + K - 1) // K + 1)
ans = min(ans, (W - y_max - 1 + K - 1) // K + 1)

print (ans)
