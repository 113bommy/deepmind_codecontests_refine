from bisect import bisect_left
n, Q = [int(x) for x in input().split()]
stx = [[int(x) for x in input().split()] for i in range(n)]
q = [int(input()) for i in range(Q)]
stx.sort(key=lambda x: x[2])
ans = [-1 for i in range(Q)]
skip = [-1 for i in range(Q)]

for (s, t, x) in stx:
  begin = bisect_left(q, s-x)
  end = bisect_left(q, t-x)
  while begin<end:
    if skip[begin]==-1:
      ans[begin] = x
      skip[begin] = end
      begin += 1
    else:
      begin = skip[begin]
for e in ans:
  print(e)