from math import ceil

n = int(input())

a = list(map(int, input().split()))

print(min(max(a), ceil((2 * sum(a)) / n + 1e-7)))
