n,k = map(int,input().split())
p = list(map(int,input().split()))
c = list(map(int,input().split()))
p = [pi-1 for pi in p]

ans = -1e18
for i in range(n):
  cur = p[i]
  loop = [c[cur]]
  cnt = 1
  ans = max(ans,c[cur])
  while cur != i and cnt<k:
    cur = p[cur]
    tmp = loop[-1]+c[cur]
    loop.append(tmp)
    ans = max(ans,tmp)
    cnt += 1
  #print(loop)
  if cnt==k or loop[-1]<=0:continue
  a = k//len(loop) * loop[-1]
  b = (k//len(loop)-1) * loop[-1]
  ans = max(ans,a,b)
  for _ in range(k%len(loop)):
    a += c[cur]
    ans = max(ans,a)
    cur = p[cur]
  cur = i
  for _ in range(len(loop)):
    b += c[cur]
    ans = max(ans,b)
    cur = p[cur]
print(ans)