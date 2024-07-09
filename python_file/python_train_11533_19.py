from collections import deque
INF=1001001001
dy=[0,1,0,-1]
dx=[1,0,-1,0]
my=[-2,-2,-2,-2,-2,-1,-1,-1,-1,0,0,1,1,1,1,2,2,2,2,2]
mx=[2,1,0,-1,-2,2,1,-1,-2,2,-2,2,1,-1,-2,2,1,0,-1,-2]
h,w=map(int,input().split())
ch,cw=map(int,input().split())
ch-=1
cw-=1
dh,dw=map(int,input().split())
dh-=1
dw-=1
s=[list(input()) for i in range(h)]
dist=[[INF for i in range(w)] for j in range(h)]
dist[ch][cw]=0
d=deque([])
d.append([ch,cw])

while d:
  nowh,noww=d.popleft()
  for i in range(4):
    th=nowh+dy[i]
    tw=noww+dx[i]
    if 0<=th<=h-1 and 0<=tw<=w-1 and dist[th][tw]>dist[nowh][noww] and s[th][tw]==".":
      d.appendleft([th,tw])
      dist[th][tw]=dist[nowh][noww]
  for i in range(20):
    th=nowh+my[i]
    tw=noww+mx[i]
    if 0<=th<=h-1 and 0<=tw<=w-1 and dist[th][tw]>dist[nowh][noww]+1 and s[th][tw]==".":
      d.append([th,tw])
      dist[th][tw]=dist[nowh][noww]+1

ans=dist[dh][dw]
if ans==INF:
  ans=-1
print(ans)