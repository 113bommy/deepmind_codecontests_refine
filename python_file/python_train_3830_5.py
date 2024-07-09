n, k = map(int, input().split())
a = list(map(int, input().split()))
minus = [-x for x in a if x < 0]
plus = [x for x in a if x >= 0]
minus.sort()
plus.sort()


def cnt(x):
    ans = 0
    if x < 0:
        r = 0
        x = -x
        for num in minus[::-1]:
            while r < len(plus) and plus[r] * num < x:
                r += 1
            ans += len(plus) - r
        return ans

    r = 0
    for num in minus[::-1]:
        if num * num <= x:
            ans -= 1
        while r < len(minus) and minus[r] * num <= x:
            r += 1
        ans += r
    r = 0
    for num in plus[::-1]:
        if num * num <= x:
            ans -= 1
        while r < len(plus) and plus[r] * num <= x:
            r += 1
        ans += r
    ans //= 2
    ans += len(minus) * len(plus)
    return ans

right = 10**18+1
left = -(10**18+1)

while left+1 < right:
    mid = (left + right)//2

    if cnt(mid) < k:
        left = mid
    else:
        right = mid

print(int(right))