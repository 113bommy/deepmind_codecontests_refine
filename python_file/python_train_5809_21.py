from bisect import bisect_left
n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
l, r = 0, 10000000000
while r - l > 1:
    m = (l + r) // 2
    res = 0
    for x in a:
        res += n - bisect_left(a, m - x)
    if res >= k:
        l = m
    else:
        r = m
b = [0] * (n + 1)
for i in range(1, n + 1):
    b[i] = b[i - 1] + a[n - i]
cnt = 0
ans = 0
for x in a:
    t = n - bisect_left(a, l - x)
    ans += b[t] + x * t
    cnt += t
print(ans - (cnt - k) * l)
