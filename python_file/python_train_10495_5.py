import sys
sys.setrecursionlimit(10**7)
h,w = map(int,input().split())
s = [list(input()) for _ in range(h)]
visited = [[False]*w for _ in range(h)]

def dfs(y,x):
    visited[y][x] = True
    blk, wht = 0,0
    for dy,dx in zip((-1,1,0,0),(0,0,-1,1)):
        ny,nx = y+dy, x+dx
        if (not (0<=ny<h)) or (not (0<=nx<w)) or visited[ny][nx]:
            continue
        if s[y][x]!=s[ny][nx]:
            nb,nw = dfs(ny,nx)
            blk += nb
            wht += nw
    if s[y][x]=='#':
        blk += 1
    else:
        wht += 1
    return blk, wht

ans = 0
for i in range(h):
    for j in range(w):
        if not visited[i][j]:
            blk, wht = dfs(i,j)
            ans += blk*wht
print(ans)