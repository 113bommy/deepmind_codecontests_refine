import itertools

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = [i for i in range(n)]

def add(k, x):
  while k <= n:
    data[k] += x
    k += k & -k
def get(k):
  s = 0
  while k:
    s += data[k]
    k -= k & -k
  return s
ans = 10 ** 18
for i in itertools.combinations(c,n//2):
  j = list(set(c)-set(i))
  even = sorted([(a[k],k+1) if k % 2 else (b[k],k+1) for k in i])
  odd = sorted([(b[k],k+1) if k % 2 else (a[k],k+1) for k in j])
  prev = -1
  A = []
  for x in range(n):
    Y,X = divmod(x,2)
    if X % 2:
      now0,now1 = even[Y][0],even[Y][1]
    else:
      now0,now1 = odd[Y][0],odd[Y][1]
    if prev > now0:
      break
    else:
      A.append(now1)
    prev = now0
  else:
    data = [0]*(n+1)
    tmp = 0
    for i,z in enumerate(A):
      tmp += (n-1-i) - get(z)
      add(z,1)
    ans = min(ans,tmp)
if ans == 10 ** 18:
  print(-1)
else:
  print(ans)