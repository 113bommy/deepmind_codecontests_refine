for t in range(int(input())):
    a, b = map(int, input().split())
    print((abs(a-b) + 9) // 10)