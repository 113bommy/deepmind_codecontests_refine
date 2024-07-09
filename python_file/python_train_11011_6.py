N, K = map(int, input().split())
*A, = map(int, input().split())
for k in range(41):
    B = [0] * N
    for i, a in enumerate(A):
        l = max(0, i - a)
        r = min(N - 1, i + a)
        B[l] += 1
        if r + 1 < N: B[r + 1] -= 1
    for i in range(1, N): B[i] += B[i-1]
    A = B
    if k == K - 1: break
print(*A)