import math
 
def div(m):
  d = {}
  temp = int(math.sqrt(m))+1
  for i in range(2, temp):
    while m%i== 0:
      m //= i
      if i in d:
        d[i] += 1
      else:
        d[i] = 1
  if d == {}:
    d[m] = 1
  else:
    if m in d:
      d[m] += 1
    elif m != 1:
      d[m] =1
  return d

n, m = map(int, input().split())
if m == 1:
  print(1)
  exit()
#print(div(m))
from math import factorial
d = div(m)
#print(d)
ans = 1
for i in d.values():
  ans *= int(factorial(i+n-1)) // int(factorial(n-1)) // int(factorial(i))
  ans %= 10**9+7
print(ans)