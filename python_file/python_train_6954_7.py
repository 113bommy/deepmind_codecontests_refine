MOD = 10**9+7
h, w = map(int, input().split())
S = [input() for _ in range(h)]
L = [[0]*w for _ in range(h)]
R = [[0]*w for _ in range(h)]
U = [[0]*w for _ in range(h)]
D = [[0]*w for _ in range(h)]
for i in range(h):
  for j in range(w):
    if j > 0:
      if S[i][j-1] == ".":
        L[i][j] = L[i][j-1]+1
      if S[i][w-j] == ".":
        R[i][w-1-j] = R[i][w-j]+1
    if i > 0:
      if S[i-1][j] == ".":
        U[i][j] = U[i-1][j]+1
      if S[h-i][j] == ".":
        D[h-1-i][j] = D[h-i][j]+1
ans = 0
for i in range(h):
  for j in range(w):
    if S[i][j] == ".":
      temp = L[i][j]+R[i][j]+U[i][j]+D[i][j]+1
      ans = max(ans, temp)
print(ans)