N, M = map(int, input().split())

for base in range(1, M//N+1)[::-1]:
    if M % base != 0:
        continue
    print(base)
    break
