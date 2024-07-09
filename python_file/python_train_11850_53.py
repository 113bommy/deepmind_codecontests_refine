import math

n,m = map(int,input().split())

max_n = math.floor(m/n)

for i in range(1,max_n+1)[::-1]:
    if m % i == 0:
        print(i)
        break