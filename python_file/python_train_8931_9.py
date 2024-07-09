import math

N, K = list(map(int, input().split()))

p = 0
for i in range(N):
    p += 1/N * (1/2) ** max(0, math.ceil(math.log2(K/(i+1))))

print(p)