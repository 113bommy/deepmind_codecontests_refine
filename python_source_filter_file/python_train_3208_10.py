n = int(input())

if n % 2 == 0:
  print(n*(n-2)//2)
  for i in range(1,n):
    for j in range(i+1,n+1):
      if i + j != n:
        print(i,j)
else:
  print(n*(n-2)//2 + 1)
  for i in range(1,n):
    for j in range(i+1,n+1):
      if i + j != n + 1:
        print(i,j)
