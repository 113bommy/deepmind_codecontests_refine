N, Ma, Mb = map(int, input().split())
L = [[float("inf")]*410 for i in range(410)]
P = [[0, 0]]
L[0][0] = 0

for i in range(N):
    a, b, c = map(int, input().split())
    OldP = P.copy()
    Lsub = [L[p[0]][p[1]] for p in OldP]
    for xp, p in enumerate(OldP):
        if L[p[0]+a][p[1]+b] == float("inf"):
            P.append([p[0]+a, p[1]+b])
        L[p[0]+a][p[1]+b] = min(L[p[0]+a][p[1]+b], Lsub[xp]+c)
g = [Ma, Mb]
ans = float("inf")
while g[0]<410 and g[1]<410:
    ans = min(ans, L[g[0]][g[1]])
    g[0] += Ma
    g[1] += Mb
print(ans if ans != float("inf") else -1)
