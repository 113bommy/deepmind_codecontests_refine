n, k = map(int, input().split())
A = [*map(int, input().split())]
for i in range(k):
    B = [0]*(n+1)
    for j in range(n):
        l = max(0, j - A[j])
        r = min(n, j + A[j] + 1)
        B[l] += 1; B[r] -= 1
    for j in range(n-1): B[j+1] += B[j]
    B.pop()
    if A == B: break
    A = B
print(*A, sep=' ')
