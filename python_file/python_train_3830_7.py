import sys
n,k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
l = sys.maxsize * (-1)
r = sys.maxsize

while l+1 < r:
  x = (l+r)//2
  def isOk():
    tot = 0
    for i in range(n):
      if a[i] < 0:
        l = -1
        r = n
        while (l+1<r):
          c = (l+r)//2;
          if (a[c] * a[i] < x):
            r = c
          else:
            l = c
        tot += n-r
      else:
        l = -1
        r = n
        while (l+1<r):
          c = (l+r)//2
          if (a[c] * a[i] < x):
            l = c
          else:
            r = c
        tot += r
      if (a[i]*a[i] < x):
        tot -= 1
    tot /= 2
    return tot < k
  if (isOk()):
    l = x
  else:
    r = x;
print(l)