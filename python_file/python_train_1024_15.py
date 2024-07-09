n, m = map(int, input().split())
infty = int(1E9)
d = [[infty for i in range(n)] for j in range(n)]
edges = []

for i in range(n):
  d[i][i] = 0

for _ in range(m):
  x, y, c = map(int, input().split())
  x -= 1; y -= 1
  edges.append((x, y, c))
  d[x][y] = d[y][x] = c

for k in range(n):
  for i in range(n):
    for j in range(n):
      d[i][j] = min(d[i][j], d[i][k] + d[k][j])

ans = 0
for e in edges:
  x, y, c = e;
  need = False
  for i in range(n):
    for j in range(n):
      if d[i][j] == d[i][x] + d[j][y] + c:
        need = True
        break
  ans += not need

print(ans)