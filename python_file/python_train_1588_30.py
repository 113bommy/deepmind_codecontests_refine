import math
for t in range(int(input())):
    sides=int(input())
    N=2*sides
    angle=90-(180/N)
    #print(angle)
    rad=math.radians(angle)
    #print(rad)
    ans=math.tan(rad)
    print(ans)