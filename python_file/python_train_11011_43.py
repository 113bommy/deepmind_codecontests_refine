import itertools

N, K = map(int, input().split())
A = list(map(int, input().split()))
end = [N] * N

for _ in range(K):
    lst = [0] * N
    for i, a in enumerate(A):
        lst[max(0, i - a)] += 1
        if i + a + 1 < N:
            lst[i + a + 1] -= 1
    A = list(itertools.accumulate(lst))
    if A == end:
        break
print(*A)
