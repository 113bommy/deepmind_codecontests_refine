N,M = map(int,input().split())
A = list(map(int,input().split()))
A.sort()
import bisect
for i in range(M):
    bisect.insort(A,A[-1]/2)
    A.pop(-1)
for i in range(N):
    A[i] = int(A[i])
print(sum(A))