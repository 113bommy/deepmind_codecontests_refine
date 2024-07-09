from itertools import permutations

def WarshallFloyd(M):
    N = len(M)
    for k in range(N):
        for j in range(N):
            for i in range(N):
                M[i][j] = min(M[i][j], M[i][k] + M[k][j])
    return M

INF = 1e10

N, M, K = map(int, input().split())
R = [int(i) - 1 for i in input().split()]
E = [[INF] * N for _ in range(N)]
for a, b, c in (map(int, input().split()) for _ in range(M)):
    a -= 1; b -= 1
    E[a][b] = E[b][a] = c

E = WarshallFloyd(E)
ans = min(sum(E[p[i]][p[i + 1]] for i in range(K - 1)) for p in permutations(R))
print(ans)
