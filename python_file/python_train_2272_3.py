N, C = map(int, input().split())
D = [list(map(int, input().split())) for i in range(C)]
c = [list(map(int, input().split())) for i in range(N)]
col = [[0]*3 for i in range(C)]
for i in range(N):
    for j in range(N):
        p = c[i][j]-1
        for k in range(C):
            col[k][(i+j)%3] += D[p][k]
ans = 10**18
for i in range(C):
    for j in range(C):
        if i == j:
            continue
        for k in range(C):
            if i == k or j == k:
                continue
            ans = min(ans, col[i][0] + col[j][1] + col[k][2])
print(ans)