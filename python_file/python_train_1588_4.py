import math

t=  int(input())
while t:
    t-=1
    n = int(input())
    angleinDegrees = 90 - 90/n 

   # print(angleinDegrees)

    angleInRad = math.radians(angleinDegrees)

    print('%.8f' %math.tan(angleInRad) )