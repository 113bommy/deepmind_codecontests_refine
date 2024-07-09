import sys
input = sys.stdin.readline
from bisect import bisect_left, bisect_right

N, K = map(int, input().split())
A = list(map(int, input().split()))
A.sort()

neg = bisect_left(A, 0)
pos = bisect_right(A, 0)

def less(x):
    res = 0
    b = 0
    for i in range(0, neg):
        while b != N and A[i] * A[b] >= x:
            b += 1
        while b != 0 and A[i] * A[b - 1] < x:
            b -= 1
        res += max(i - b, 0)
    for i in range(neg, pos):
        if x > 0:
            res += i
    for i in range(pos, N):
        while b != N and A[i] * A[b] < x:
            b += 1
        while b != 0 and A[i] * A[b - 1] >= x:
            b -= 1
        res += min(b, i)
    return res

l = - (10 ** 18 + 1)
r = - l
while l + 1 < r:
    m = (l + r) // 2
    if less(m) < K:
        l = m
    else:
        r = m
print(l)
