import math 
A,B,C,D=map(int,input().split())
print("Yes" if math.ceil(A/D) >= math.ceil(B/C) else "No")