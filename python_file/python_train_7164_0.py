# D - AtCoder Express 2

N, M, Q = map(int, input().split())
G = [[0] * (N+1) for _ in range(N+1)]

for _ in range(M):
    L, R = map(int, input().split())
    G[L][R] += 1

for i in range(N+1):
    for j in range(N):
        G[i][j+1] += G[i][j]

for _ in range(Q):
    p, q = map(int, input().split())
    ans = 0
    for i in range(p, q+1):
        ans += G[i][q] - G[i][p-1]
    print(ans)