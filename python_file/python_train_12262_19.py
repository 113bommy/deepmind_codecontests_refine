import math
k=int(input())
a=0
for i in range(1,k+1):
  for j in range(1,k+1):
    for h in range(1,k+1):
      a+=math.gcd(math.gcd(i,j),h)
    
print(a)