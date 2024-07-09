import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

K, Q = na()
d = na()

for z in range(Q):
    n, x, m = na()

    n -= 1

    rem = n%K
    pre = m-1
    x %= m
    ans = 0
    for i in range(rem):
        pre = x
        x = (x + d[i]) % m
        if pre < x:
            ans += 1

    lpre = 0
    turn = 0
    # print(d[rem:] +  d[:rem])
    for v in d[rem:] + d[:rem]:
        cur = (lpre + v) % m
        if lpre < cur:
            turn += 1
        lpre = cur
    my = turn*m - lpre
    # print(turn, m, my, n//K, x)
    ans += (my * (n//K) + m-x-1) // m - (m-x-1)//m
    print(ans)
