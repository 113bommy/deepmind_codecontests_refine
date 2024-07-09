D, G = map(int, input().split())
p = [list(map(int, input().split())) for _ in range(D)]
visited = [0] * D
def dfs(s, c):
  temp = 10 ** 3
  for i in range(D):
    if visited[i] == 0:
      visited[i] = 1
      if s >= p[i][0] * (i + 1) * 100 + p[i][1]:
        temp = min(temp, dfs(s - p[i][0] * (i + 1) * 100 - p[i][1], c + p[i][0]))
      else:
        temp = min(temp, -(-s // ((i + 1) * 100)) + c, p[i][0] + c)
      visited[i] = 0
  return temp
print(dfs(G, 0))