N,M = map(int, input().split())
E = [[int(e) for e in input().split()] for _ in range(M)]

E.sort()
inf = 10**15
seg = [inf]*(2*N-1)

def update(k, x):
    k += N-1
    seg[k] = x
    while k:
        k = (k-1)//2
        seg[k] = min(seg[2*k+1], seg[2*k+2])
        
def query(p, q):
    p += N-1
    q += N-2
    res = inf
    while q-p > 1:
        if p&1 == 0:
            res = min(res, seg[p])
        if q&1 == 1:
            res = min(res, seg[q])
            q -= 1
        p //= 2
        q = (q-1)//2
    if p == q:
        res = min(res, seg[q])
    else:
        res = min(res, seg[p], seg[q])
    return res

update(0, 0)
for e in E:
    d = query(e[1]-1, N)
    l = query(e[0]-1, N)
    if l+e[2] < d:
        update(e[1]-1, l+e[2])

if seg[-1] == inf:
    print(-1)
else:
    print(seg[-1])