import math
t=int(input())
a=[]
for i in range(t):
    a.append(int(input()))
for num in a:
    print(round(math.floor(num-1)/2))