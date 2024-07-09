n, k = map(int, input().split())
T = [[] for _ in range(n)]
E = []
for _ in range(n-1):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  T[a].append(b)
  T[b].append(a)
  E.append((a, b))
d = k//2
def dfs(vs):
  dist = [-1]*n
  stack = []
  cnt = 0
  for v in vs:
    stack.append(v)
    dist[v] = 0
  while stack:
    v = stack.pop()
    for nv in T[v]:
      if dist[nv] == -1:
        dist[nv] = dist[v] + 1
        if dist[nv] > d:
          cnt += 1
        stack.append(nv)
  return cnt
ans = n
if k%2 == 0:
  for i in range(n):
    ans = min(ans, dfs([i]))
else:
  for l in E:
    ans = min(ans, dfs(l))
print(ans)