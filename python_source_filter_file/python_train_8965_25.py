for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    print(a, [d, c][a==c])
