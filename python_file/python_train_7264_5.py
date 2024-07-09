#reference Segment-Tree code from:https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree

def bisect(pos):
  l=-1
  r=n
  while r-l!=1:
    mid=(l+r)//2
    if arr[mid][0]>=pos:
      r=mid
    else:
      l=mid
  return r

mod=998244353
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
arr=sorted(arr,key=lambda x:x[0])
poss=[]
for i in range(n):
  poss.append(bisect(arr[i][0]+arr[i][1]))
poss.append(n)

offset=2**((n-1).bit_length())
st=[0]*(2*offset)

def update(pos,x):
  pos+=offset
  st[pos]=x
  while pos>1:
    y=st[pos^1]
    if x<=y:
      break
    pos>>=1
    st[pos]=x

def get_max(l,r):
  ret=0
  l+=offset
  r+=offset
  while l<r:
    if r&1:
      ret=max(ret,st[r-1])
    if l&1:
      ret=max(ret,st[l])
      l+=1
    l>>=1
    r>>=1
  return ret

for i in range(n):
  update(i,poss[i])
for i in range(n-1,-1,-1):
  poss[i]=get_max(i,poss[i])
  update(i,poss[i])

dp=[0]*(n+1)
dp[-1]=1
for i in range(n-1,-1,-1):
  dp[i]+=dp[i+1]
  dp[i]%=mod
  pos=poss[i]
  dp[i]+=dp[pos]
  dp[i]%=mod
print(dp[0]%mod)