import sys
input = sys.stdin.readline

h,w,k=map(int, input().split())
x1,y1,x2,y2=map(int, input().split())
x1-=1;y1-=1;x2-=1;y2-=1
c=[input() for _ in range(h)]
INF=10**14
dp=[[INF for _ in range(w)] for _ in range(h)]
dp[x1][y1]=0
from collections import deque
q=deque()

q.append((x1,y1))
dxy=[(1,0),(0,1),(-1,0),(0,-1)]

while q:
    x,y=q.popleft()
    for dx,dy in dxy:
        for j in range(1,k+1):
            if not 0<=x+dx*j<h:break
            if not 0<=y+dy*j<w:break
            if c[x+dx*j][y+dy*j]=='@':break
            if dp[x+dx*j][y+dy*j]>dp[x][y]+1:
                dp[x+dx*j][y+dy*j]=dp[x][y]+1
                q.append((x+dx*j,y+dy*j))
            elif dp[x+dx*j][y+dy*j]==dp[x][y]+1:continue###
            elif dp[x+dx*j][y+dy*j]<=dp[x][y]:break###
    
            
            if x+dx*j==x2 and y+dy*j==y2:
                print(dp[x2][y2])
                exit()

        
print(-1)