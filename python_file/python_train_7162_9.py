import sys
input = sys.stdin.readline

N = int(input())
XY = [[set() for i in range(10**5+1)] for j in range(2)]
for i in range(N):
  x, y = map(int, input().split())
  XY[0][x].add(y)
  XY[1][y].add(x)

is_visited_x = [False] * (10**5 + 1)
def dfs(x):
  global is_visited_x
  is_visited_x[x] = True
  stack = [[x], []]
  idx = 0
  num_e = 0
  num_xy = [1, 0]
  parent = 0
  while stack[0] or stack[1]:
    node = stack[idx][-1]
    children = XY[idx][node]
    if children:
      child = children.pop()
      XY[idx-1][child].remove(node) # 今来た道を削除
      num_e += 1
      if child in stack[idx-1]:
        continue
      stack[idx-1].append(child)
      num_xy[idx-1] += 1
      is_visited_x[child] += idx
      idx = (idx + 1) % 2
    else:
      stack[idx].pop()
      idx = (idx + 1) % 2
  return num_e, num_xy

ans = 0
for x in range(1, 10**5+1):
  if is_visited_x[x]:
    continue
  num_e, num_xy = dfs(x)
  ans += num_xy[0]*num_xy[1] - num_e

print(ans)