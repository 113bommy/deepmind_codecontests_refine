n = int(input())
for i in range(0, n):
    for j in range(1, n // 2 + 1):
        print(i * (n // 2) + j, n * n - (i * (n // 2) + j) + 1, end=" ")
    print()
