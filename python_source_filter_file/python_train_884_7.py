n = int(input())
a = int(input())
b = int(input())
c = int(input())

r = b - c

x = 0
if r < a and b < n:
    x += (n - b) // r + 1
    n -= r * x
x += n // a
print(x)