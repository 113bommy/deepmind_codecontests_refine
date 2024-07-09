N, C = map(int, input().split())
D = [list(map(int, input().split())) for i in range(C)]
G = [list(map(int, input().split())) for i in range(N)]

change = [[0]*C for i in range(3)]
for c in range(C):
    for i in range(1, N+1):
        for j in range(1, N+1):
            change[(i+j) % 3][c] += (D[G[i-1][j-1]-1][c] if G[i-1][j-1] != c+1 else 0)

ans = float('inf')
for c1 in range(C):
    for c2 in range(C):
        for c3 in range(C):
            if len(set((c1, c2, c3))) != 3:
                continue
            ans = min(ans, change[0][c1] + change[1][c2] + change[2][c3])

print(ans)
