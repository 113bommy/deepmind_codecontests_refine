(n, m) = list(map(int, input().split()))

xs = [0 for i in range(n + 1)]
ys = [0 for i in range(n + 1)]
xsum, ysum = 0, 0
s = n * n

for i in range(m):
    (x, y) = list(map(int, input().split()))
    if not xs[x]:
        s -= n - 1
        s += ysum - ys[y]

    if not ys[x]:
        s -= n - 1
        s += xsum - xs[x]

    if not xs[x] and not ys[y]:
        s -= 1

    if not xs[x]:
        xsum += 1
        xs[x] += 1

    if not ys[x]:
        ysum += 1
        ys[y] += 1

    print(s, end=" ")

print("")