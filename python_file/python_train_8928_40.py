import queue

INF = 10 ** 9

H, W, K = map(int, input().split())
sx, sy, gx, gy = map(int, input().split())

sentinels = [-1] * (W+2)
MAP = [sentinels]
for _ in range(H):
    MAP.append( [-1] + list(map(lambda c: INF if c == '.' else -1, input())) + [-1] )
MAP.append(sentinels)

q = queue.Queue()
q.put((sx, sy))
MAP[sx][sy] = 0
while not q.empty():
    x, y = q.get()
    for d in range(1, K+1):
        if MAP[x+d][y] > MAP[x][y] + 1:
            MAP[x+d][y] = MAP[x][y] + 1
            q.put((x+d, y))
        elif MAP[x+d][y] < MAP[x][y] + 1:
            break
    for d in range(1, K+1):
        if MAP[x-d][y] > MAP[x][y] + 1:
            MAP[x-d][y] = MAP[x][y] + 1
            q.put((x-d, y))
        elif MAP[x-d][y] < MAP[x][y] + 1:
            break
    for d in range(1, K+1):
        if MAP[x][y+d] > MAP[x][y] + 1:
            MAP[x][y+d] = MAP[x][y] + 1
            q.put((x, y+d))
        elif MAP[x][y+d] < MAP[x][y] + 1:
            break
    for d in range(1, K+1):
        if MAP[x][y-d] > MAP[x][y] + 1:
            MAP[x][y-d] = MAP[x][y] + 1
            q.put((x, y-d))
        elif MAP[x][y-d] < MAP[x][y] + 1:
            break

if MAP[gx][gy] == INF:
    print(-1)
else:
    print(MAP[gx][gy])