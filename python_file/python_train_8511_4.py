import math

def gcd_ext(a, b):
    x, y, lastx, lasty = 0, 1, 1, 0
    while b != 0:
        q = a // b
        a, b = b, a % b
        x, y, lastx, lasty = lastx - q * x, lasty - q * y, x, y
    return (lastx, lasty)

n = int(input())
divisor_list = []
n *= 2
for x in range(2, int(n ** 0.5) + 1):
    if n % x == 0:
        divisor_list.append([x, n // x])
ans = n - 1
for m1, m2 in divisor_list:
    if math.gcd(m1, m2) != 1:
        continue
    p, q = gcd_ext(m1, m2)
    tmp = (-1 * m1 * p) % (m1 * m2)
    ans = min(tmp, ans)
    tmp = (-1 * m2 * q) % (m1 * m2)
    ans = min(tmp, ans)
print(ans)