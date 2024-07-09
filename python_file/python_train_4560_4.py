import math

N, K = map(int, input().split())
A = list(map(int, input().split()))
F = list(map(int, input().split()))
A.sort(reverse=True)
F.sort()

l = -1
r = A[0] * F[-1]
while l+1 < r:
    c = (l + r) // 2
    practice = 0
    for i in range(N):
        practice += max(math.ceil(A[i] - c / F[i]), 0)
    if practice <= K:
        r = c
    else:
        l = c
print(r)