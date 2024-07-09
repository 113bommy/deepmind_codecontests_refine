n, k = map(int, input().split())
a = list(map(int, input().split()))
posi = []
nega = []
zero = []
for i in range(n):
    if a[i] < 0:
        nega.append(a[i] * -1)
    elif a[i] > 0:
        posi.append(a[i])
    else:
        zero.append(a[i])
zero = len(zero)
posi.sort()
nega.sort()
lp, ln = len(posi), len(nega)
if k <= lp * ln:
    l, r = 0, 10 ** 18
    while r - l > 1:
        m = (l + r) // 2
        cnt = lp * ln
        cur = 0
        for i in range(ln)[::-1]:
            while cur < lp and posi[cur] < (m + nega[i] - 1) // nega[i]:
                cur += 1
            cnt -= cur
        if cnt >= k:
            l = m
        else:
            r = m
    print(-1 * l)
elif k <= n * (n - 1) // 2 - (lp * (lp - 1) // 2) - (ln * (ln - 1) // 2):
    print(0)
else:
    k -= n * (n - 1) // 2 - (lp * (lp - 1) // 2) - (ln * (ln - 1) // 2)
    l, r = 0, 10 ** 18
    while r - l > 1:
        m = (l + r) // 2
        cnt = 0
        cur = ln - 1
        for i in range(ln):
            while cur and nega[cur] > m // nega[i]:
                cur -= 1
            if cur > i:
                cnt += cur - i
        cur2 = lp - 1
        for i in range(lp):
            while cur2 and posi[cur2] > m // posi[i]:
                cur2 -= 1
            if cur2 > i:
                cnt += cur2 - i
        if cnt >= k:
            r = m
        else:
            l = m
    print(r)