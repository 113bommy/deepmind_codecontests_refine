from collections import deque
H,W=map(int,input().split())
Ch,Cw=map(int,input().split())
Dh,Dw=map(int,input().split())
Ch-=1;Cw-=1;Dh-=1;Dw-=1
C=(Ch,Cw)
D=(Dh,Dw)
S=[list(input()) for i in range(H)]
dist=[[10**15 for j in range(W)] for i in range(H)]
dist[Ch][Cw]=0
q=deque([C])
dx=[1,0,-1,0]
dy=[0,1,0,-1]
while(len(q)>0):
    x,y=q.popleft()
    for k in range(4):
        nx=x+dx[k]
        ny=y+dy[k]
        if 0<=nx<H and 0<=ny<W:
            if S[nx][ny]=="#":
                continue
            if dist[nx][ny]>dist[x][y]:
                dist[nx][ny]=dist[x][y]
                q.appendleft((nx,ny))
    for i in range(-2,3):
        for j in range(-2,3):
            nx=x+i
            ny=y+j
            if 0<=nx<H and 0<=ny<W:
                if S[nx][ny]=="#":
                    continue
                if dist[nx][ny]>dist[x][y]+1:
                    dist[nx][ny]=dist[x][y]+1
                    q.append((nx,ny))
if dist[Dh][Dw]==10**15:
    print(-1)
else:
    print(dist[Dh][Dw])
