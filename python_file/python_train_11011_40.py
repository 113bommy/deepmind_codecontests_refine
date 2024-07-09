from itertools import accumulate
N, K, *A = map(int, open(0).read().split())
for _ in range(min(K, 41)):
    next_A = [0] * (N + 1)
    for i, a in enumerate(A):
        next_A[max(0, i - a)] += 1
        next_A[min(N, i + a + 1)] -= 1
    A = list(accumulate(next_A))
A.pop()
print(*A)