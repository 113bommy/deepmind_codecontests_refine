n, k = list(map(int, input().split(' ')))
print(n - 100 * (10 - min(10, k) * 2))