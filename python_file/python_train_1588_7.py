import math

t = int(input())

for _ in range(t):
    n = int(input())
    n *= 2
    
    ia = 180*(n-2)/(2*n)
    r = math.radians(ia)
    print(round(math.tan(r), 7))