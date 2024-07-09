import queue

n,m=map(int,input().split())

fri=[[] for i in range(n)]

for i in range(m):
  ai,bi=map(int,input().split())
  fri[ai-1].append(bi-1)
  fri[bi-1].append(ai-1)

seen=[0 for i in range(n)]



ans=0
for i in range(n):
  if seen[i]==1:
    continue
  cnt=1
  q=queue.Queue()
  q.put(i)
  seen[i]=1
  while not q.empty():
    p=q.get()
    for pnext in fri[p]:
      if seen[pnext]==0:
        q.put(pnext)
        seen[pnext]=1
        cnt+=1
  ans=max(ans,cnt)

print(ans)