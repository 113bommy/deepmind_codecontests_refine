q = int(input())
for i in range(q):
    n, a, b = map(int, input().split())
    if b <= a:
        print((n // 2) * b + (n % 2) * a)
    else:
        print(n * a)