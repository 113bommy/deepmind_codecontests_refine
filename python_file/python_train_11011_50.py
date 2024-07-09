N, K = map(int, input().split())
A = list(map(int, input().split()))

for _ in range(K):
    B = [0] * (N + 1)
    for i, a in enumerate(A):
        B[max(0, i - a)] += 1
        B[min(N, i + a + 1)] -= 1
    for i in range(N):
        B[i + 1] += B[i]
    A = B[:N]

    if min(A) >= N:
        break

print(*A)

