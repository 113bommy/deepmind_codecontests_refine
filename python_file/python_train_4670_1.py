n, m = map(int, input().split())
edges = {}
for _ in range(m):
  a, b = map(int, input().split())
  if a-1 in edges:
    edges[a-1].append(b-1)
  else:
    edges[a-1] = [b-1]
  if b-1 in edges:
    edges[b-1].append(a-1)
  else:
    edges[b-1] = [a-1]

end1, end2 = a-1, b-1

visited = [False for _ in range(n)]
visited[end1] = True
visited[end2] = True

seti = set([end1, end2])
path = [end1, end2]
while True:
  reme = None
  for _a in edges[end1]:
    if _a not in seti:
      reme = _a
      break
  if reme is not None:
    end1 = _a
    seti.add(_a)
    path = [_a] + path
  else:
    for _a in edges[end2]:
      if _a not in seti:
        reme = _a
        break
    if reme is not None:
      end2 = _a
      seti.add(_a)
      path += [_a]
  if reme is None:
    break

print(len(path))
print(*map(lambda x: x+1, path))
