import math
n = int(input())
for i in range(n):
    g = int(input())
    u= math.tan(math.pi/(2*g))
    if (g%2)==0:
        print('%.9f'%(1.0000000000/u))
    else:
        print('%.9f'%math.hypot(u,0.5))
        
