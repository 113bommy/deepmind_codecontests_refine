import sys
l, r = map(int, sys.stdin.readline().split())
if r - l <= 1:
  print(-1)
elif r - l == 2:
  if l%2 == 1:
    print(-1)
  else:
    print(l,l+1,l+2)
elif l%2 == 0:
  print(l+1,l+2,l+3)
else:
  print(l,l+1,l+2)
