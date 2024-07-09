from heapq import *

class UnionFind():
    def __init__(self,n):
        self.n=n
        self.parents=[-1]*n
    def find(self,x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x]=self.find(self.parents[x])
            return self.parents[x]
    def unite(self,x,y):
        x = self.find(x)
        y = self.find(y)
        if x==y:
            return
        if self.parents[x]>self.parents[y]:
            x,y=y,x
        self.parents[x]+=self.parents[y]
        self.parents[y]=x
    def size(self, x):
        return -self.parents[self.find(x)]
    def same(self, x, y):
        return self.find(x) == self.find(y)
    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i)==root]
    def roots(self):
        return [i for i,x in enumerate(self.parents) if x<0]
    def group_count(self):
        return len(self.roots())
    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

n=int(input())
X=[[0,0] for i in range(n)]
Y=[[0,0] for i in range(n)]
edge=[[0,0] for i in range(n)]
for i in range(n):
  x,y=map(int,input().split())
  X[i]=[x,i]
  Y[i]=[y,i]
  edge[i]=[x,y]
X.sort()
Y.sort()
hq=[]
heapify(hq)
for i in range(n-1):
  x1,j1=X[i]
  x2,j2=X[i+1]
  y1,k1=Y[i]
  y2,k2=Y[i+1]
  heappush(hq,(x2-x1,j1,j2))
  heappush(hq,(y2-y1,k1,k2))
ans=0
uf=UnionFind(n)
while hq:
  w,s,t=heappop(hq)
  if uf.find(s)!=uf.find(t):
    uf.unite(s,t)
    ans+=w
print(ans)