N,C = map(int,input().split())
D = [list(map(int,input().split())) for _ in range(C)]
Grid = [list(map(int,input().split())) for _ in range(N)]

SumCost = [[0 for _ in range(C)] for _ in range(3)]
for c in range(1,C+1):
  for i in range(N):
    for j in range(N):
      g = ((i+1)+(j+1))%3
      SumCost[g][c-1] += D[Grid[i][j]-1][c-1]

ans = 10**18
for c1 in range(1,C+1):
  for c2 in range(1,C+1):
    for c3 in range(1,C+1):
      if c1 == c2 or c2 == c3 or c3 == c1:
        continue
      ans = min(ans,SumCost[0][c1-1]+SumCost[1][c2-1]+SumCost[2][c3-1])
print(ans)