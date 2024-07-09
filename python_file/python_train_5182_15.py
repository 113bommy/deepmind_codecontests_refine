ni = lambda: int(input())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))

n,k = nm()
p = nl()
c = nl()

for i in range(n):
  p[i]-=1

ans = -10**(18)
for si in range(n):
  x = si
  s = []
  tot = 0
  while(True):
    x = p[x]
    s.append(c[x])
    tot += c[x]
    if x == si:
      break
  l = len(s)
  t = 0
  for i in range(l):
    t += s[i]
    if i+1>k:
      break
    now = t
    if tot > 0:
      e = (k-(i+1))//l
      now += tot*e
    ans = max(ans,now)

print(ans)