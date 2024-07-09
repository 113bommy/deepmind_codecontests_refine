N, c = map(int, input().split())
D = [[int(i) for i in input().split()] for j in range(c)]
C = [[int(i) for i in input().split()] for j in range(N)]
A = [[0 for i in range(c)] for j in range(3)]
for i in range(N):
    for j in range(N):
        for k in range(c):
            A[(i+j)%3][k] += D[C[i][j]-1][k]

ans = 1e9
for i in range(c):
    for j in range(i):
        for k in range(j):
            for l in range(3):
                ans = min(ans, A[l][i]+A[(l+1)%3][j]+A[(l+2)%3][k],
                          A[l][i]+A[(l-1)%3][j]+A[(l-2)%3][k])
print(ans)
