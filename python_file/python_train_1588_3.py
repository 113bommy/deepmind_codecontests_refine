from math import tan 
def Inscribed(n):
    r = 1/(2 * tan((180 / n) * 3.1415926535 / 180)); 
    return r
  
for _ in range(int(input())):
    n = int(input())
    if n==2:
        print(1.000000000)
        continue
    print('{0:.12}'.format(2*Inscribed(2*n))) 