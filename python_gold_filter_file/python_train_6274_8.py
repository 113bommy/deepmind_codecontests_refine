for _ in range(int(input())):

    n = int(input())

    arr = list(map(int, input().strip().split()))

    print(*arr[::-1])