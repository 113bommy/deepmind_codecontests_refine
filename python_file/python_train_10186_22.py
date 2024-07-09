# ABC 073 D
import itertools

N, M, R = map(int,input().split())
s = list(map(int,input().split()))
D = [[10**9+7 for k in range(N)] for l in range(N)]
for k in range(N):
    D[k][k] = 0
for k in range(M):
    A, B, C = map(int,input().split())
    A -= 1
    B -= 1
    D[A][B] = C
    D[B][A] = C

for p in range(N):
    for q in range(N):
        for r in range(N):
            D[q][r] = min(D[q][r], D[q][p]+D[p][r])

cities = list(itertools.permutations(s))
ans = 10**9+7
for p in cities:
    t = 0
    for k in range(R-1):
        t += D[p[k]-1][p[k+1]-1]
    ans = min(ans,t)

print(ans)