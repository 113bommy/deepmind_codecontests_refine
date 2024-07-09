
import sys
input = sys.stdin.readline
def main():
  n,q=map(int,input().split())
  c=list(map(int,input().split()))
  lr=[list(map(int,input().split())) for _ in range(q)]
  lri=[[lr[i][0],lr[i][1],i] for i in range(q)]
  lri.sort(key=lambda x:x[1])
  
  class BIT:
      def __init__(self, n):
          self.n = n
          self.data = [0]*(n+1)
          self.el = [0]*(n+1)
      def sum(self, i):
          s = 0
          while i > 0:
              s += self.data[i]
              i -= i & -i
          return s
      def add(self, i, x):
          # assert i > 0
          self.el[i] += x
          while i <= self.n:
              self.data[i] += x
              i += i & -i
      def get(self, i, j=None):
          if j is None:
              return self.el[i]
          return self.sum(j) - self.sum(i)

  bt=BIT(n+1)
  dc={}
  ans=[0]*q
  j=0
  for i in range(n):
    x=c[i]
    if x in dc:
      bt.add(dc[x],-1)
    bt.add(i+1,1)
    dc[x]=i+1
    while j<q and i+1==lri[j][1]:
      l,r,k=lri[j]
      ans[k]=bt.get(l-1,r)
      j+=1
    if j==q:break
  print(*ans,sep='\n')


if __name__=='__main__':
  #import datetime
  #print(datetime.datetime.now())
  main()
  #print(datetime.datetime.now())
