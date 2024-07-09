from itertools import combinations

n, k = map(int, input().split())
xlist, ylist, xy = [], [], []
for _ in range(n):
  x, y = map(int, input().split())
  xlist.append(x)
  ylist.append(y)
  xy.append((x, y))

xlist.sort()
ylist.sort()
ans = (xlist[-1] - xlist[0]) * (ylist[-1] - ylist[0])
for x1, x2 in combinations(xlist, r=2):
  for y1, y2 in combinations(ylist, r=2):
    tmpk = 0
    for i in range(n):
      if x1 <= xy[i][0] <= x2 and y1 <= xy[i][1] <= y2:
        tmpk += 1

      if tmpk >= k:
        tmp_ans = (x2 - x1) * (y2 - y1)
        if ans > tmp_ans:
          ans = tmp_ans

print(ans)
