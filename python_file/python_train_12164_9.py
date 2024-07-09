def solve():
  n=int(input())
  arr1=list(map(int,input().split()))
  arr2=list(map(int,input().split()))
  tlist=[0]
  for val in arr1:
    tlist.append(tlist[-1]+val)
  t=tlist[-1]
  ans=0
  for i in range(1,2*t):
    tt=i/2
    tmp=10**18
    for j in range(n):
      if tt<=tlist[j]:
        tmp=min(tmp,arr2[j]+(tlist[j]-tt))
      elif tlist[j+1]<=tt:
        tmp=min(tmp,arr2[j]+(tt-tlist[j+1]))
      else:
        tmp=min(tmp,arr2[j])
    tmp=min(tmp,tt)
    tmp=min(tmp,t-tt)
    ans+=tmp
  print(ans/2)
solve()