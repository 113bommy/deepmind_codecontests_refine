from itertools import accumulate

n, k = map(int, input().split())
a = list(map(int, input().split()))

cnt = 1
while cnt <= k and min(a) < n:
    li = [0] * (n + 1)
    for i, e in enumerate(a):
        l = max(0, i - e)
        r = min(n, i + e + 1)
        li[l] += 1
        li[r] -= 1

    a = list(accumulate(li))[:-1]

    cnt += 1

print(*a)
