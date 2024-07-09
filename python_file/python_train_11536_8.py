from collections import defaultdict
import sys

def dfs(visited, graph, grapht, graph2, num, x):
  visited[x] = 1

  for nx in graph[x]:
    if not visited[nx]:
      dfs(visited, graph, grapht, graph2, num, nx)

  t = set()
  if num[x]==1 and len(grapht[x])%2==0:
    for e in grapht[x]:
      graph2[x].add(e)
      t.add(e)
  elif num[x]==-1 and len(grapht[x]) and len(grapht[x])%2==0:
    for e in grapht[x]:
      graph2[x].add(e)
      t.add(e)
    tt = grapht[x].pop()
    graph2[tt].add(x)
    graph2[x].remove(tt)
    num[tt] *= -1
  elif num[x]==1 and len(grapht[x])%2==1:
    for e in grapht[x]:
      graph2[x].add(e)
      t.add(e)
    tt = grapht[x].pop()
    graph2[tt].add(x)
    graph2[x].remove(tt)
    num[tt] *= -1
  else:
    for e in grapht[x]:
      graph2[x].add(e)
      t.add(e)
  for e in t:
    if e in grapht[x]:
      grapht[x].remove(e)
    if x in grapht[e]:
      grapht[e].remove(x)

if __name__ == "__main__":
  sys.setrecursionlimit(1000000)
  input = sys.stdin.readline
  n, m = map(int, input().split())

  if m%2==1:
    print(-1)
    exit()

  graph = defaultdict(set)
  grapht = defaultdict(set)
  for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].add(b)
    graph[b].add(a)
    grapht[a].add(b)
    grapht[b].add(a)

  graph2 = defaultdict(set)
  visited = [0]*n
  num = [1]*n

  dfs(visited, graph, grapht, graph2, num, 0)

  for i in range(n):
    if len(graph2[i])%2==1:
      print(-1)
      exit()

  for i in range(n):
    for e in graph2[i]:
      print(i+1, e+1)