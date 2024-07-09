import bisect
N,M = map(int, input().split())
A = sorted(map(int, input().split()))
for i in range(M):
    bisect.insort(A, A.pop()//2)
print(sum(A))