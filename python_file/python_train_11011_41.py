from itertools import accumulate
n, k = map(int, input().split())
a = list(map(int, input().split()))

for i in range(k):
    b = [0] * (n + 1)
    for j in range(n):
        b[max(0, j - a[j])] += 1
        b[min(n, j + a[j] + 1)] -= 1
    a = list(accumulate(b))
    if sum(a) == n ** 2:
        a.pop()
        print(*a)
        exit()

a.pop()
print(*a)