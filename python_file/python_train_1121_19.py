import sys
input = sys.stdin.readline
N,M = map(int,input().split())
ABC = [tuple(map(int,input().split())) for i in range(N)]
DEF = [tuple(map(int,input().split())) for i in range(M)]
INF = float('inf')

def solve():
    xs = set([-INF,0,INF])
    ys = set([-INF,0,INF])
    for a,b,c in ABC:
        xs.add(a)
        xs.add(b)
        ys.add(c)
    for d,e,f in DEF:
        xs.add(d)
        ys.add(e)
        ys.add(f)
    xs = sorted(xs)
    ys = sorted(ys)
    xd = {x:i*2 for i,x in enumerate(xs)}
    yd = {y:i*2 for i,y in enumerate(ys)}

    W = len(xs)*2 - 1
    H = len(ys)*2 - 1
    S = [[0]*W for _ in range(H)]
    for y in (0,-1):
        for x in range(W):
            S[y][x] = 1
    for x in (0,-1):
        for y in range(H):
            S[y][x] = 1
    for a,b,c in ABC:
        for x in range(xd[a], xd[b]+1):
            S[yd[c]][x] = 1
    for d,e,f in DEF:
        for y in range(yd[e], yd[f]+1):
            S[y][xd[d]] = 1

    from collections import deque
    sx,sy = xd[0]+1, yd[0]+1
    q = deque([(sx,sy)])
    visited = [[0]*W for _ in range(H)]
    visited[sy][sx] = 1
    dxy = [(0,1),(1,0),(0,-1),(-1,0)]
    ans = (xs[sx//2+1] - xs[sx//2]) * (ys[sy//2+1] - ys[sy//2])
    while q:
        x,y = q.popleft()
        for dx,dy in dxy:
            nx,ny = x+dx,y+dy
            if S[ny][nx] == 1: continue
            nnx,nny = nx+dx,ny+dy
            if visited[nny][nnx]: continue
            visited[nny][nnx] = 1
            q.append((nnx,nny))
            tx,ty = (nx,nny) if nx%2 else (nnx,ny)
            assert tx%2 and ty%2
            w = xs[tx//2+1] - xs[tx//2]
            h = ys[ty//2+1] - ys[ty//2]
            ans += w*h
            if ans==INF:
                print('INF')
                exit()
    print(ans)
solve()