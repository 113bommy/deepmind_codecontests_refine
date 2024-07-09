from math import *

K = int(input())

sum = 0
for i in range(K):
  for j in range(K):
    for k in range(K):
      sum += gcd((i+1),gcd((j+1),(k+1)))

print(sum)
