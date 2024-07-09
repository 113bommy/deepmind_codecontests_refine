n, m = map(int, input().split())

yd = {}
i = 2
while m != 1:
  while m % i == 0:
    if i in yd:
      yd[i] += 1
    else:
      yd[i] = 1
    m //= i
  i += 1

ans = 1
for v in yd.values():
  start = v + n - 1
  c = 1
  for _ in range(v):
    c *= start
    start -= 1
  d = 1
  for _v in range(v):
    d *= (_v + 1)
  ans *= (c // d)
print(ans % 1000000007)
