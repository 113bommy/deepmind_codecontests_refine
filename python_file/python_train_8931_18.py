N,K=map(int, input().split())

t = 0
import math
for x in range(1, min(N,K-1)+1):
    t += (1-pow(0.5, math.ceil(math.log2(K/x))))

print(1 - t / N)