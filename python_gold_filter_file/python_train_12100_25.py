t = int(input())
for _ in range(t):
    x, y, a, b = map(int, input().split())
    if abs(x - y) % (a + b) == 0:
        print(abs(x - y) // (a + b))
    else:
        print(-1)
