N = int(input())

res = 100000

for i in range(N+1):
  cc = 0
  t = i
  while t>0:
    cc += t%6
    t = int(t/6)
  t = N-i
  while t>0:
    cc += t%9
    t = int(t/9)
  if res > cc:
    res = cc

print(res)
  