n, m = map(int, input().split())

for i in reversed(range(1, m//n + 1)):
    if m % i == 0:
        print(i)
        break
