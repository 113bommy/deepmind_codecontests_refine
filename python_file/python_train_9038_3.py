n,k = map(int, input().split())
l = [tuple(map(int, input().split())) for _ in range(n)]
ok = min(w+d*(k-1) for w,d in l)
ng = 0
while ok-ng > 1:
  mid = (ok+ng)//2
  tot = 0
  for w,d in l:
    if w > mid:
      continue
    tot += 1 + (mid-w)//d
  if tot >= k:
    ok = mid
  else:
    ng = mid
print(ok)