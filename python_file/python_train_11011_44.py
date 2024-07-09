from itertools import accumulate

N, K = map(int, input().split())
A = list(map(int, input().split()))
for _ in range(min(K, 100)):
    tmp = [0]*N
    for i, ai in enumerate(A):
        tmp[max(0, i-ai)] += 1
        if i+ai+1 < N:
            tmp[i+ai+1] -= 1
    A = accumulate(tmp)
print(*A)
