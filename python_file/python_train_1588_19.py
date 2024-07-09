import math
def check(n):
    pi = math.pi
    num = math.sin(pi*(n-1)/(2*n))
    den = math.sin(pi/(2*n))
    return num/den
    
for _ in range(int(input())):
    n = int(input())
    print(check(n))