import math
A,B = map(int,input().split())
gcd = math.gcd(A,B)
print(int(A*B/gcd))