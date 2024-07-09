from collections import deque

h, w = [int(_) for _ in input().split()]
G = [list(input()) for _ in range(h)]

que = deque()
for i in range(h):
    for j in range(w):
        if G[i][j] == '#':
            que.append((i, j, 0))
cnt = 0
while que:
    i, j, c = que.popleft()

    for ni, nj in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        if i + ni < 0 or j + nj < 0: continue
        if i + ni >= h or j + nj >= w: continue

        if G[i + ni][j + nj] == '.':
            G[i + ni][j + nj] = '#'
            que.append((i + ni, j + nj, c + 1))
            cnt = max(cnt, c + 1)
print(cnt)
