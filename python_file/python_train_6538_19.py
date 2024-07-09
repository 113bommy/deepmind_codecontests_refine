from collections import deque

h,w = map(int,input().split())
l = [list(input()) for i in range(h)]

dis = [[10000]*w for i in range(h)]
q = deque([])

for i in range(h):
    for j in range(w):
        if l[i][j] == "#":
            q.append([i,j,0])
            dis[i][j] = 0
dx = [0,0,1,-1]
dy = [1,-1,0,0]
while q:
    x,y,d = q.popleft()

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < h and 0 <= ny < w and dis[nx][ny] > d+1:
            dis[nx][ny] = d + 1
            q.append([nx,ny,d+1])

ans = 0
for i in dis:
    ans = max(ans,max(i))
print(ans)
