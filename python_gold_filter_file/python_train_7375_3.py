N = int(input())
A = list(map(int, input().split()))

A.sort()
print(sum(A[N:3 * N:2]))