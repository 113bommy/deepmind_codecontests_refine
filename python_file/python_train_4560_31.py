N, K = map(int, input().split())
A = list(map(int, input().split()))
F = list(map(int, input().split()))

A.sort()
F.sort(reverse=True)
AF = [A[i] * F[i] for i in range(N)]

l = -1
r = max(AF)
while l + 1 < r:
    x = (l + r) // 2
    s = sum([max(A[i] - x//F[i], 0) for i in range(N)])
    if s <= K:
        r = x
    else:
        l = x

print(r)