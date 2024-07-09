n,m,p = map(int, input().split())
edge = []
e1 = [list() for _ in range(n+1)]
for _ in range(m):
  a,b,c = map(int, input().split())
  edge.append((a,b,p-c))
  e1[a].append(b)
dis = [float("inf")]*(n+1)
dis[1] = 0
t = []
for i in range(n):
  for a,b,c in edge:
    if dis[b] > dis[a] + c:
      dis[b] = dis[a] + c
      if i == n-1:
        t.append(b)
s = set(t)
while t:
  v = t.pop()
  for x in e1[v]:
    if x == n:
      print(-1)
      exit(0)
    if x in s:
      continue
    s.add(x)
    t.append(x)
print(max(0,-dis[n]))
