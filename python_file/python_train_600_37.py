n,m = map(int,input().split())
d = []
for _ in range(m):
  l,r,c = map(int,input().split())
  d.append([l,r,c])
d.sort(key=lambda x:x[0])
g = [float("inf") for _ in range(n+1)]
g[1] = 0
f = 1
for i in range(m):
  if d[i][0] > f:
    print(-1)
    exit()
  f = max(f,d[i][1])
  sm = d[i][2]+g[d[i][0]]
  if g[d[i][1]] > sm:
    g[d[i][1]] = sm
    j = d[i][1]-1
    while g[j] > sm:
      g[j] = sm
      j -= 1
if g[n] != float("inf"):
  print(g[n])
else:
  print(-1)