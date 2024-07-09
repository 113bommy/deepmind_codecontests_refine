import sys
sys.setrecursionlimit(200000)
H,W=map(int,input().split())
S=[]
for i in range(H):
    S.append(input())

ans=0
dx=[0,0,1,-1]
dy=[1,-1,0,0]

was=[[0 for i in range(W)] for j in range(H)]

def dfs(x,y):
    global cc
    global was
    was[x][y]=1
    if S[x][y]=="#":
        cc[1]+=1
    else:
        cc[0]+=1
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if nx>=0 and ny>=0 and nx<H and ny<W and S[nx][ny]!=S[x][y] and not was[nx][ny]:
            dfs(nx,ny)

for i in range(H):
    for j in range(W):
        if not was[i][j]:
            cc=[0]*2
            dfs(i,j)
            ans+= cc[1]*cc[0]

print(ans)