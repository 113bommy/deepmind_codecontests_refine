from itertools import combinations
N,K=map(int,input().split())

xs = set()
ys = set()
inl = []

for i in range(N):
    x,y=map(int,input().split())
    inl.append((x,y))
    xs.add(x)
    ys.add(y)

xs = list(xs)
ys = list(ys)
xs.sort()
ys.sort()

res = 9223372036854775807
for xlow, xhi in combinations(xs,2):
    for ylow, yhi in combinations(ys,2):
        cnt = 0
        for x, y in inl:
            cnt += (x >= xlow and x <= xhi and y >= ylow and y <= yhi)
        if cnt == K:
            res = min(res,(xhi - xlow) * (yhi - ylow))
print(res)
