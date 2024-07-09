# cook your dish here
import math
t=int(input())
pie= math.pi
for _ in range(t):
    n=int(input())
    an=360/(2*n)
    

    start=(180-an)/2
    start=math.radians(start)
    cnt=math.tan(start)/2
    print(2*cnt)