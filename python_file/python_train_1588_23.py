from math import pi, cos, sin, tan
cot = lambda x: 1/tan(x)
for tc in range(int(input())):
    n = int(input())
    print(1/(2*sin(pi/(4*n))))