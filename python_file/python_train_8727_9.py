n = int(input())
for x in range(1, 3501):
  for y in range(1, 3501):
    t = 4 * x * y - n * y - n * x
    if(t <= 0):
      continue
    if((n * x * y) % t == 0):
      print(x, y, (n * x * y) // t)
      exit(0)