import math
a, b = map(int, input().split())
g = math.gcd(a, b)
print(a * b // g)