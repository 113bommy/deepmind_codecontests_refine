n, m = list(map(int, input().split()))
graph = [float("INF") for i in range(n)]
graph[0] = 0
edge = [tuple(map(int, input().split())) for i in range(m)]
for i in range(2*n):
  flag = False
  for e in edge:
    a, b, c = e
    a, b, c = a-1, b-1, -c
    if graph[b] > graph[a]+c:
      if b==n-1:
        flag = True
      graph[b] = graph[a]+c
if flag:
  print("inf")
else:
  print(-graph[n-1])