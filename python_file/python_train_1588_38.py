import math
for i in range(int(input())):
    sides = 2*int(input())
    radius = 1/(2*math.sin(math.pi/sides))

    length = 1
    angle_count = 1
    angle = (2*math.pi)/sides
    orig_angle = angle
    while angle < math.pi/2:
        # print(angle)
        length += 2*math.cos(angle)
        angle += orig_angle
    
    print(length)
