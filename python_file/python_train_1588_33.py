import math

t = int(input())
for ii in range(t):
    n = int(input())
    r = 1 / (2 * math.tan(math.pi / (2 * n)))
    print(2 * r)
