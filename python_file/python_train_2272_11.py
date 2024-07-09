import itertools

N, C = map(int, input().split())
D = [ [ int(x) for x in input().split() ] for _ in range(C) ]
CC = [ [ int(x)-1 for x in input().split() ] for _ in range(N) ]
cost = [ [ 0 for _ in range(C) ] for _ in range(3) ]

for c in range(C):
    for i in range(N):
        for j in range(N):
            cost[(i+j) % 3][c] += D[CC[i][j]][c]

ans = float("inf")
for c in itertools.permutations(range(C), 3):
    tmp = 0
    for j in range(3):
        tmp += cost[j][c[j]]

    ans = min(ans, tmp)

print(ans)