#21:10
h,w = map(int,input().split())
raw = []
for x in range(h):
  raw.append(input())
xx = []
for x in range(h):
  now = []
  tmp = 0
  for y in range(w):
    if raw[x][y] == '.':
      tmp += 1
    else:
      now += [tmp] * tmp
      tmp = 0
      now.append(0)
  now += [tmp] * tmp
  xx.append(now)
yy = []
for y in range(w):
  now = []
  tmp = 0
  for x in range(h):
    if raw[x][y] == '.':
      tmp += 1
    else:
      now += [tmp] * tmp
      tmp = 0
      now.append(0)
  now += [tmp] * tmp
  yy.append(now)
'''
for x in range(h):
  print(xx[x])
for y in range(w):
  print(yy[y])
'''
maxi = 0
for x in range(h):
  for y in range(w):
    maxi = max(maxi,xx[x][y]+yy[y][x]-1)
print(maxi)