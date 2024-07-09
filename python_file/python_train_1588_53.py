from math import pi, cos, sqrt

def sol(n):
    cth = cos(pi/n)
    x = 1/sqrt(2*(1-cth))
    if n%2:
        return x*2
    else:
        return sqrt(x*x-0.25)*2

N = int(input())
while N > 0:
    ans = sol(int(input()))
    print(ans)
    N -= 1
