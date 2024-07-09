class SegmentTreeMax():
  def __init__(self,n,init):
    self.offset=2**((n-1).bit_length())
    self.tree=[init]*(2*self.offset)
    self.init=init
  def update(self,pos,val):
    pos+=self.offset
    self.tree[pos]=val
    while pos>1:
      pos=pos//2
      self.tree[pos]=max(self.tree[2*pos],self.tree[2*pos+1])
  def query(self,l,r):
    l+=self.offset
    r+=self.offset
    ret=self.init
    while l<=r:
      ret=max(ret,self.tree[r])
      r=(r-1)//2
      ret=max(ret,self.tree[l])
      l=(l+1)//2
    return ret

n=int(input())
h=list(map(int,input().split()))
a=list(map(int,input().split()))
st=SegmentTreeMax(max(h)+1,0)
for i in range(n):
  val=a[i]+st.query(0,h[i]-1)
  st.update(h[i],val)
print(max(st.tree))