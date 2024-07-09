h,w = map(int,input().split())
raw = []
for _ in range(h):
  raw.append(input())
ans = [[0 for _ in range(w)] for _ in range(h)]
#print(raw)
#print(ans)
for x in range(h):
  tmp = 0
  for y in range(w):
    if raw[x][y] == '.':
      tmp += 1
    else:
      for j in range(tmp):
        ans[x][y-j-1] += tmp
      tmp = 0
  for j in range(tmp):
    ans[x][y-j] += tmp
for y in range(w):
  tmp = 0
  for x in range(h):
    if raw[x][y] == '.':
      tmp += 1
    else:
      for i in range(tmp):
        ans[x-i-1][y] += tmp
      tmp = 0
  for i in range(tmp):
    ans[x-i-1][y] += tmp
can = []
for x in range(h):
  can.append(max(ans[x]))
print(max(can)-1)