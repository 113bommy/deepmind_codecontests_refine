n,m=map(int,input().split())
arr=list(map(int,input().split()))
left={0:0,1:0}
right={0:0,1:0}
s=0
g=0
if m not in arr:
  print(0)
else:
  for i in range(arr.index(m)+1,n):
    if arr[i]<m:
      s+=1
    elif arr[i]>m:
      g+=1
    if g-s in right.keys():
      right[g-s]+=1
    else:
      right[g-s]=1
  s=0
  g=0
  for i in range(arr.index(m)-1,-1,-1):
    if arr[i]<m:
      s+=1
    elif arr[i]>m:
      g+=1
    if g-s in left.keys():
      left[g-s]+=1
    else:
      left[g-s]=1
  count=0
  for i in left.keys():
    if -i in right.keys():
      count+=left[i]*right[-i]
    if -i+1 in right.keys():
      count+=left[i]*right[-i+1]
  count+=left[0]+left[1]+right[0]+right[1]
  count+=1
  print(count)

