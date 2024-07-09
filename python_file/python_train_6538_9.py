H, W = map(int, input().split())
l = [list(input()) for _ in range(H)]

from collections import deque
q = deque()
for i, r in enumerate(l):
    for j, c in enumerate(r):
        if c == '#':
            l[i][j] = 0
            q.append((i, j))
d = [(0, 1), (0, -1), (1, 0), (-1, 0)]

while q:
    y, x = q.popleft()
    for dy, dx in d:
        if (0 <= y+dy < H) and (0 <= x+dx < W) and l[y+dy][x+dx] == '.':
            l[y+dy][x+dx] = l[y][x] + 1
            q.append((y+dy, x+dx))

m = 0
for r in l:
    for c in r:
        if m < c:
            m = c
print(m)