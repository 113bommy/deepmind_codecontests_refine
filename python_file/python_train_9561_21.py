import itertools

N,K = map(int, input().split())

X = []
Y = []

for _ in range(N):
  x,y = map(int, input().split())
  X.append(x)
  Y.append(y)

# 全部数えても間に合う

min_area = 5*10**18

for x1,x2 in itertools.combinations(X,2):
  for y1,y2 in itertools.combinations(Y,2):
    if x1 > x2:
      x1,x2 = x2,x1
    if y1 > y2:
      y1,y2 = y2,y1

    area = (x2-x1) * (y2-y1)
    if area > min_area:
      continue
      
    cnt = 0
    for x,y in zip(X,Y):
      if x1 <= x <= x2 and y1 <= y <= y2:
        cnt += 1
    if cnt < K:
      continue
      
    min_area = area
    
print(min_area)