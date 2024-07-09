from itertools import combinations
N, K = map(int, input().split())
xy = [tuple(map(int, input().split())) for i in range(N)]

ans = float("inf")
for p1, p2 in combinations(xy, 2):
    x1 = p1[0]
    x2 = p2[0]
    if x2 < x1:
        x1, x2 = x2, x1
        #x2 > x1
    for p3, p4 in combinations(xy, 2):
        y1 = p3[1]
        y2 = p4[1]
        if y2 < y1:
            y1, y2 = y2, y1
        # y2 >= y1
        count = 0
        for x, y in xy:
            if x >= x1 and x <= x2 and y >= y1 and y <= y2:
                count += 1

        if count >= K:
            ans = min(ans, (x2-x1)*(y2-y1))


print(ans)
