import math
import bisect
N, M = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
for _ in range(M):
    x=math.floor(A.pop(N-1)/2)
    bisect.insort(A,x)
print(sum(A))
