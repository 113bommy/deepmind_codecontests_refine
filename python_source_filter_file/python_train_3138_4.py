n = int(input())
a = list(map(int, input().split()))
a.sort()
sm = sum(a)
ans = sm
for i in range(1, n):
    s = sm
    x = a[0]
    y = a[i]
    for j in range(1, y + 1):
        if y % j == 0:
            q = x * j
            w = y // j
            s = s - x - y + q + w
            if s < ans: ans = s
print(ans)

