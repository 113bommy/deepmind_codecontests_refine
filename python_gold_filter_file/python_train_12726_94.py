for _ in range(int(input())):
    n, m = map(int, input().split())
    s = 0
    if n == 1:
        print(0)
    elif n == 2:
        print(m)
    else:
        print(m*2)