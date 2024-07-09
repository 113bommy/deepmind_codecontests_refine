import copy

H, W = map(int, input().split())
grid = [[1 if c == "." else 0 for c in input()] for _ in range(H)]

L = copy.deepcopy(grid)
R = copy.deepcopy(grid)
U = copy.deepcopy(grid)
D = copy.deepcopy(grid)

for i in range(H):
  for j in range(1, W):
    L[i][j] = (L[i][j-1] + 1) * L[i][j]
    R[i][-1-j] = (R[i][-j] + 1) * R[i][-1-j]

for j in range(W):
  for i in range(1, H):
    U[i][j] = (U[i-1][j] + 1) * U[i][j]
    D[-1-i][j] = (D[-i][j] + 1) * D[-1-i][j]

ans = 0

for i in range(H):
  for j in range(W):
    ans = max(ans, L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3, 0)

print(ans)
