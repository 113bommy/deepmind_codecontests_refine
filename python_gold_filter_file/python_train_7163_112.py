n, a, b = list(map(int, input().split()))
print(min(a, b), max(0, a + b - n))
