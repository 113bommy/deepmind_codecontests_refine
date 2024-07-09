n, t = map(int, input().split())
ab = [tuple(map(int, input().split())) for i in range(n)]

m, d = 0, [0] * t
for a, b in sorted(ab):
  m = max(m, b+d[t-1])
  for l in range(t-1,a-1,-1):
    if(b+d[l-a] > d[l]):
      d[l] = b+d[l-a]
print(m)