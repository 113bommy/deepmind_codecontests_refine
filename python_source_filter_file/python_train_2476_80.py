import math
a,b,c,d = map(int,input().split())
print("Yes" if math.ceil(c/b) <= math.ceil(d/a) else "No")