N, C = map(int, input().split())
D = [list(map(int, input().split())) for _ in range(C)]
c = [list(map(int, input().split())) for _ in range(N)]

from itertools import permutations

colors = tuple(i for i in range(C))

table = [[0 for i in range(C)] for j in range(3)]
for color in colors:
    for col in range(N):
        for row in range(N):
            table[(col+row)%3][color]+=D[c[col][row]-1][color]
            
ans = 10**9    
for i, j, k in permutations(colors, 3):
    ans = min(ans, table[0][i]+table[1][j]+table[2][k])

print(ans)