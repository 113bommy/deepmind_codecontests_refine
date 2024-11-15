import sys
inf = float('inf')
n, ma, mb = map(int, input().split())
t = [[inf] * 401 for _ in range(401)]
t[0][0] = 0
for _ in range(n):
  a, b, c = map(int, input().split())
  for aa in range(400, 0, -1):
    for bb in range(400, 0, -1):
      if t[aa][bb] == inf:
        continue
      if t[a + aa][b + bb] > c + t[aa][bb]:
        t[a + aa][b + bb] = c + t[aa][bb]
result = inf
for a in range(400, 0, -1):
  for b in range(400, 0, -1):
    if a * mb == b * ma and t[a][b] < result:
      result = t[a][b]
if result == 0:
  print(-1)
else:
  print(result)
