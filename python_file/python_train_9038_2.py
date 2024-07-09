import sys
N, K = map(int, input().split())
input = sys.stdin.readline
wd = [tuple(map(int, input().split())) for i in range(N)]
wd.sort()
d = 0
dp = [0]*N
l = 0
r = wd[0][0] + wd[0][1]*K
while(r - l > 1):
    tmp = (l+r)//2
    num = 0
    for w, d in wd:
        if w <= tmp:
            num += ((tmp - w) // d) + 1
    if num >= K:
        r = tmp
    else:
        l = tmp

print(r)
