from collections import deque
n=int(input())
arr=deque(list(map(int,input().split())))
ans=''
tmp=0
for i in range(n):
  if tmp<min(arr[0],arr[-1]):
    if arr[0]<arr[-1]:
      ans+='L'
      tmp=arr.popleft()
    else:
      ans+='R'
      tmp=arr.pop()
  elif tmp<max(arr[0],arr[-1]):
    if arr[0]<arr[-1]:
      ans+='R'
      tmp=arr.pop()
    else:
      ans+='L'
      tmp=arr.popleft()
  else:
    break
print(len(ans))
print(ans)