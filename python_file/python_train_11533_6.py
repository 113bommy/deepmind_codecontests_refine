from collections import deque

H,W = map(int,input().split())
C_pos=list(map(lambda x:int(x)-1,input().split()))
D_pos=list(map(lambda x:int(x)-1,input().split()))
Grid=[[c for c in input()] for _ in range(H)]

Dist=[[float("inf")]*W for _ in range(H)]

DX=[0,0,1,-1]

Q=deque()
Q.append((C_pos[0],C_pos[1]))
Dist[C_pos[0]][C_pos[1]]=0

while Q:
    cx,cy = Q.pop()

    for dx,dy in zip(DX,reversed(DX)):
        nx=cx+dx
        ny=cy+dy

        if 0<=nx<H and 0<=ny<W and Grid[nx][ny]=="." and Dist[nx][ny]>Dist[cx][cy]:
            Dist[nx][ny]=Dist[cx][cy]
            Q.append((nx,ny))


    for dx in range(-2,3):
        for dy in range(-2,3):
            nx=cx+dx
            ny=cy+dy
            if dx==0 and dy==0:
                continue

            if 0<=nx<H and 0<=ny<W and Grid[nx][ny]=="." and Dist[nx][ny]==float("inf"):
                Dist[nx][ny]=Dist[cx][cy]+1
                Q.appendleft((nx,ny))


ans=Dist[D_pos[0]][D_pos[1]]
if ans==float("inf"):
    print(-1)
else:
    print(ans)


