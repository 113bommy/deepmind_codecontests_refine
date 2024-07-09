import heapq

n=int(input())
arr1=list(map(int,input().split()))
arr2=list(map(int,input().split()))
q=[]
for i in range(n):
  if arr2[i]!=arr1[i]:
    heapq.heappush(q,(-arr2[i],i))
cnt=0
while q:
  val,pos=heapq.heappop(q)
  val*=-1
  diff=arr2[pos-1]+arr2[(pos+1)%n]
  move=(val-arr1[pos])//diff
  if move==0:
    break
  cnt+=move
  tmp=arr2[pos]-diff*move
  arr2[pos]=tmp
  if tmp!=arr1[pos]:
    heapq.heappush(q,(-tmp,pos))
for i in range(n):
  if arr1[i]!=arr2[i]:
    print(-1)
    break
else:
  print(cnt)