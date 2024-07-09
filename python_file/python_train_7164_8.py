N,M,Q = [int(x) for x in input().split()]
ll = [[0] * (N+1) for i in range(N+1)]
for i in range(M):
    l,r = [int(x) for x in input().split()]
    ll[l][r] += 1
for i in range(1,N+1):
    for j in range(1,N+1):
        ll[i][j] += ll[i-1][j]
for i in range(Q):
    ans = 0
    p,q = [int(x) for x in input().split()]
    for i in range(p,q+1):
        ans += ll[q][i]-ll[p-1][i]
    print(ans)