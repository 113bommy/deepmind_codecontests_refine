n, m = map(int, input().split())

if n == 1 and m == 1:
  print(0)
elif n == 1:
  print(m-2)
elif m == 1:
  print(n-2)
else:
  print((n-2)*(m-2))
