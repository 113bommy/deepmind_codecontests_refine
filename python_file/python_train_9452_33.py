#https://qiita.com/chun1182/items/ddf2b6cba932b2bb0d4e
def BF(p,n,s):
    inf=float("inf")
    d=[inf for i in range(n)]
    d[s-1]=0
    for i in range(n+1):
        for e in p:
            if e[0]!=inf and d[e[1]-1]>d[e[0]-1]+e[2]:
                d[e[1]-1] = d[e[0]-1] + e[2]
    ans1=d[-1]
    for i in range(n+1):
        for e in p:
            if e[0]!=inf and d[e[1]-1]>d[e[0]-1]+e[2]:
                d[e[1]-1] = d[e[0]-1] + e[2]
    ans2=d[-1]
    if ans1>ans2:
      return ['inf']
    else:
      return [-ans1]
n,m,p=map(int,input().split())
g=[]
for _ in range(m):
  a,b,c=map(int,input().split())
  g.append([a,b,-(c-p)])
g.append([n,n+1,0])
ans=BF(g,n+1,1)[-1]
if ans=='inf':
  print(-1)
else:
  print(max(ans,0))