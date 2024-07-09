from collections import deque

H, W = map(int, input().split())
CH, CW = map(int, input().split())
DH, DW = map(int, input().split())

S = []
for _ in range(H):
    S.append(list(input()))

d = [[-1 for i in range(W)] for j in range(H)]

Q = deque([[CH - 1, CW - 1, 0]])

while Q:
    x, y, cnt = Q.popleft()
    if d[x][y] != -1:
        continue
    d[x][y] = cnt

    for tx in range(-2, 3):
        for ty in range(-2, 3):
            nx = x + tx
            ny = y + ty
            if 0 <= nx < H and 0 <= ny < W and S[nx][ny] == '.':
                if abs(tx) + abs(ty) == 1:
                    Q.appendleft([nx, ny, cnt])
                elif abs(tx) + abs(ty) >= 2:
                    Q.append([nx, ny, cnt + 1])

ans = d[DH - 1][DW - 1]

# print(f'{d=}')
print(ans)
