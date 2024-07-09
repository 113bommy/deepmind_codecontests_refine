import sys
def input():
    return sys.stdin.readline()
n = int(input())
xd = [[int(i) for i in input().split()] for _ in range(n)]
xd.sort()


num_max = 2**(n-1).bit_length()
seg_max = [0] * (2 * num_max)
ide_ele_max = -1


def init_max(init_max_val):
    # set_val
    for i in range(n):
        seg_max[i+num_max-1] = init_max_val[i]
    # built
    for i in range(num_max-2, -1, -1):
        seg_max[i] = max(seg_max[2*i+1], seg_max[2*i+2])


def update_max(k, x):
    k += num_max-1
    seg_max[k] = x
    while k:
        k = (k-1)//2
        seg_max[k] = max(seg_max[k*2+1], seg_max[k*2+2])


def query_max(p, q):
    if q <= p:
        return ide_ele_max
    p += num_max-1
    q += num_max-2
    res = ide_ele_max
    while q-p > 1:
        if p & 1 == 0:
            res = max(res, seg_max[p])
        if q & 1 == 1:
            res = max(res, seg_max[q])
            q -= 1
        p = p//2
        q = (q-1)//2
    if p == q:
        res = max(res, seg_max[p])
    else:
        res = max(max(res, seg_max[p]), seg_max[q])
    return res


y = [0] * n
j = n-1
for x, d in reversed(xd):
    if x + d > xd[-1][0]:
        y[j] = n
    else:
        mi = 0
        ma = n - 1
        while mi != ma:
            m = (mi + ma) // 2 + 1
            if xd[m][0] < x + d:
                mi = m
            else:
                ma = m - 1
        if mi == j:
            y[j] = mi+1
        else:
            y[j] = query_max(j+1, mi+1)
    update_max(j, y[j])
    j -= 1
dp = [0] * (n + 1)
dp[-1] = 1
j = n-1
for i in y:
    if j == y[j]:
        dp[j] = dp[j+1]
    dp[j] = (dp[j + 1] + dp[y[j]]) % 998244353
    j -= 1
print(dp[0])
