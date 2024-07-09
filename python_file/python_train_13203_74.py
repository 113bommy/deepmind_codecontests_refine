for _ in range(int(input())):
  t, x, y = map(int, input().split())
  if (x + y + t) % 2 or (x + y) > t:
    print('No')
    exit(0)
print('Yes')