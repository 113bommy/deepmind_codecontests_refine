import math

s = int(input())

x1 = 1000000000
y1 = 1
x2 = math.ceil(s / x1)
y2 = x2 * x1 - s

print(0, 0, x1, y1, x2, y2)