import math

a, b, C = map(int, input().split())
h = math.sin(math.radians(90))*b
S = a*h/2
c = math.sqrt(a**2 + b**2 - 2*a*b*math.cos(math.radians(90)))
print(S)
print(a + b + c)
print(h)