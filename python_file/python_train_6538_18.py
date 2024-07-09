from collections import deque

def main():
  h,w=map(int,input().split())
  mp=[input() for _ in range(h)]
  dist=[-1]*(h*w)
  q=deque()
  
  for i in range(h):
    for j in range(w):
      if mp[i][j]=="#":
        q.append(i*w+j)
        dist[i*w+j]=0
      else:
        dist[i*w+j]=-1
  #print(q)
 
  while q:
    c=q.popleft()
    #print(c,q)
    x=c//w
    y=c%w
    for i,j in ((1,0),(0,1),(-1,0),(0,-1)):
      xx,yy=x+i,y+j
      if (0<=xx<h and 0<=yy<w and dist[xx*w+yy]==-1):
        dist[xx*w+yy]=dist[x*w+y]+1
        q.append(xx*w+yy)
      
  print(max(dist))
  return

main()
