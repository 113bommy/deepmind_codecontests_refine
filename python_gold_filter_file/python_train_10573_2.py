a, b, c, d = [int(x) for x in input().split()]
x = min(c, d, a)
y = min(b, a - x)
print(256 * x + 32 * y)