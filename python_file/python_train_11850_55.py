N, M = map(int, input().split())

work = M//N

while work > 0:
  if M%work == 0:
    print(work)
    exit(0)
  work -= 1