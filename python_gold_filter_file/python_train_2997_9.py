from collections import deque
k=int(input())
q=deque(list(range(1, 10)))
ans,x,y=0,0,0
for i in range(k):
  ans=q.popleft()
  y=ans%10
  x=ans*10+y
  if y != 0:
    q.append(x-1)
  q.append(x)
  if y != 9:
    q.append(x+1)
print(ans)
