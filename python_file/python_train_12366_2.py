H,W,K = map(int, input().split())
S = []
ans = 10**9
for i in range(H):
  S.append(input())
for div in range(1<<(H-1)):
  ID = [0]*H
  g = 0
  for i in range(H):
    ID[i] = g
    if div>>i&1:
      g += 1
  g += 1
  c = [[0]*W for i in range(g)]
  for i in range(H):
    for j in range(W):
      if S[i][j]=='1':
        c[ID[i]][j] += 1
  num = g-1
  now = [0]*g
  def add(j):
    for i in range(g):
      now[i] += c[i][j]
    for i in range(g):
      if now[i]>K:
        return False
    return True
  for j in range(W):
    if not add(j):
      num += 1
      now = [0]*g
      if not add(j):
        num = 10**9
        break
  ans = min(ans,num)
print(ans)