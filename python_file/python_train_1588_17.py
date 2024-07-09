import math

for _ in range(int(input())):
    s = int(input())
    s = s*2
    apothem = 1/(2*math.tan(math.radians(180/s)))
    print(2*apothem)