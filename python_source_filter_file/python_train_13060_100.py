n = int(input())
if n % 2 == 1:
    print(1, n-1)
else:
    if n%3 == 0:
        print(n-6, 6)
    elif n%3 == 1:
        print(n-4, 4)
    else:
        print(n-8, 8)