n, ma, mb = map(int, input().split())
abc = [list(map(int, input().split())) for _ in range(n)]

inf = 10 ** 9
lst = [[inf for _ in range(401)] for _ in range(401)]
lst[0][0] = 0
for a, b, c in abc:
    for i in range(400, -1, -1):
        if i - a < 0:
            break
        for j in range(400, -1, -1):
            if j - b < 0:
                break
            lst[i][j] = min(lst[i][j], lst[i - a][j - b] + c)

ans = inf
a = ma
b = mb
while 1:
    try:
        ans = min(ans, lst[a][b])
        a += ma
        b += mb
    except IndexError:
        break
if ans == inf:
    print(-1)
else:
    print(ans)