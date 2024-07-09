import sys
from math import sqrt
input = sys.stdin.readline
N = int(input())
ps = [tuple(map(int, input().split())) for _ in range(N)]
rang = 0
for t in ps:
  rang = max(rang, abs(t[0]), abs(t[1]))
def calc(x, y):
  res = 0
  for t in ps:
    u, v = t
    res = max(res, sqrt((x - u) ** 2 + (y - v) ** 2))
  return res

x0 = -1000
x3 = 1000
x1 = (x0 * 2 + x3) / 3
x2 = (x0 + x3 * 2) / 3
res = float("inf")
xl = 0
yl = 0
for i in range(0, rang * 2 + 1, 10):
  u = i - rang
  for j in range(0, rang * 2 + 1, 10):
    v = j - rang
    if calc(xl, yl) > calc(u, v):
      xl = u
      yl = v
x0 = xl - 10
x3 = xl + 10
while x3 - x0 > 0.1 ** 12:
  x1 = (x0 * 2 + x3) / 3
  x2 = (x0 + x3 * 2) / 3

  cc1 = 0
  cc2 = 0

  y0 = yl - 10
  y3 = yl + 10
  y1 = (y0 * 2 + y3) / 3
  y2 = (y0 + y3 * 2) / 3

  while y3 - y0 > 0.1 ** 12:
    y1 = (y0 * 2 + y3) / 3
    y2 = (y0 + y3 * 2) / 3
    c1 = calc(x1, y1)
    c2 = calc(x1, y2)
    if c1 < c2: y3 = y2
    else: y0 = y1

  cy1 = y1 + 0

  y0 = yl - 10
  y3 = yl + 10
  y1 = (y0 * 2 + y3) / 3
  y2 = (y0 + y3 * 2) / 3

  while y3 - y0 > 0.1 ** 12:
    y1 = (y0 * 2 + y3) / 3
    y2 = (y0 + y3 * 2) / 3
    c1 = calc(x2, y1)
    c2 = calc(x2, y2)
    if c1 < c2: y3 = y2
    else: y0 = y1

  cy2 = y1 + 0

  cc1 = calc(x1, cy1)
  cc2 = calc(x2, cy2)
  if cc1 < cc2: x3 = x2
  else: x0 = x1
  res = min(cc1, cc2)

print(res)