n, m = map(int, input().split())

g = m // n
while 1:
    if m % g == 0:
        break
    g -= 1

print(g)