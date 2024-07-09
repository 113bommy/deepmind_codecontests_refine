N, M = map(int, input().split())

for i in range(M//N+1)[::-1]:
    if M % i == 0:
        print(i)
        break
else:
    print(1)