import sys
from math import sqrt
from itertools import combinations
def resolve():
    eps = 1e-7
    N, K, *xyc = map(int, sys.stdin.read().split())
    x = xyc[::3]
    y = xyc[1::3]
    ci = list(zip(x, y))
    _r = xyc[2::3]
    l = 0
    r = 10 ** 6
    while l + eps < r:
        T = (l + r) / 2
        rad = [(T/_r[i])**2 for i in range(N)]
        ans = 0
        xys = []
        for i, j in combinations(range(N), 2):
            cx1, cy1 = ci[i]
            cx2, cy2 = ci[j]
            xt = cx2-cx1
            yt = cy2-cy1
            XY = xt**2+yt**2
            a = (XY+rad[i]-rad[j])/2
            d = XY*rad[i]-a**2
            if d < eps:
                continue
            x1 = (a*xt+yt*sqrt(d))/XY+cx1
            y1 = (a*yt-xt*sqrt(d))/XY+cy1
            x2 = (a*xt-yt*sqrt(d))/XY+cx1
            y2 = (a*yt+xt*sqrt(d))/XY+cy1
            xys.append([x1, y1])
            xys.append([x2, y2])
        xys.extend(ci)
        for X, Y in xys:
            tmp = 0
            for (x, y), k in zip(ci, rad):
                if (x-X)**2+(y-Y)**2 < k+eps:
                    tmp += 1
            ans = max(ans, tmp)
            if ans >= K:
                break
        if ans >= K:
            r = T
        else:
            l = T
    print(r)
resolve()