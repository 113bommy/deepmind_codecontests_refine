import sys
sys.setrecursionlimit(10 ** 9)
input = sys.stdin.readline

H,W = map(int,input().split())
S = [input() for _ in range(H)]

seen = [[False for _ in range(W)] for _ in range(H)]
dx = [1,-1,0,0]
dy = [0,0,1,-1]
numb = 0
numw = 0

def dfs(y,x):
  global numb
  global numw
  seen[y][x] = True
  if S[y][x] == '#':
    numb += 1
  if S[y][x] == '.':
    numw += 1
  for i in range(4):
    if not(0<=y+dy[i]<H) or not(0<=x+dx[i]<W):
      continue
    if seen[y+dy[i]][x+dx[i]]:
      continue
    if S[y][x] == S[y+dy[i]][x+dx[i]]:
      continue
    dfs(y+dy[i],x+dx[i])

ans = 0
for i in range(H):
  for j in range(W):
    numb = 0
    numw = 0
    if S[i][j] == '#' and not seen[i][j]:
      dfs(i,j)
      ans += numb * numw
print(ans)
