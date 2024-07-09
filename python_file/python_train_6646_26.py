from collections import Counter as C
N, M = map(int, input().split())
A = [[int(a)-1 for a in input().split()] for _ in range(N)]
X = [1] * M
mi = 1 << 100
for i in range(M):
    c = C([min([(j, A[i][j]) for j in range(M) if X[A[i][j]]])[1] for i in range(N)])
    a = max([(c[a], a) for a in c])[1]
    mi = min(mi, c[a])
    X[a] -= 1
print(mi)