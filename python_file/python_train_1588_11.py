import math


pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
t = int(input())
for ii in range(t):
    n = int(input()) * 2
    if n % 4 != 0:
        print(1 / math.sin(pi / n))
    else:
        print(math.sqrt((1 / math.sin(pi / n)) * (1 / math.sin(pi / n)) - 1))