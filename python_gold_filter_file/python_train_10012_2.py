for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    x = a[-2]
    y = len(a[:n-2])
    
    if y>=x:
        print(x-1)
    else:
        print(y)
