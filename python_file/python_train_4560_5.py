import sys
input = sys.stdin.readline
n, k = map(int, input().split())
a = sorted(list( map(int, input().split()) ))
f = sorted(list( map(int, input().split()) ), reverse=True)

lft = -1
rgt = 10**12
while rgt-lft > 1:
    mid = ( rgt+lft ) // 2
    cnt = 0

    for i, e in enumerate(a):
        cnt += max( 0, e-mid//f[i] )

    if cnt <= k:
        rgt = mid
    else:
        lft = mid

print(rgt)