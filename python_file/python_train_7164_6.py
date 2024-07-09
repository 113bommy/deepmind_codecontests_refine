N, M ,Q = map(int, input().split())
train = [list(map(int, input().split())) for i in range(M)]
qs = [list(map(int, input().split())) for i in range(Q)]
ns = []
for i in range(N+1):
    ns.append([0]*(N+1))
for l, r in train:
    for i in range(r, N+1):
        ns[l][i] += 1
for p, q in qs:
    ans = 0
    for i in range(p, q+1):
        ans += ns[i][q]
    print(ans)

