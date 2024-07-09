import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline
N, Z, W = [int(x) for x in input().strip().split()]
a = [int(x) for x in input().strip().split()]
d = {}
def minmax(x, y, c, f):
    # print('x={}, y={}, c={}, f={}'.format(x, y, c, f))
    if (c, f) in d:
        return d[(c, f)]
    if c == N:
        return abs(x - y)
    if f == 0:
        ret = -float('inf')
        for i in range(1, N - c + 1):
            ret = max(ret, minmax(a[c+i-1], y, c+i, f^1))
    else:
        ret = float('inf')
        for i in range(1, N - c + 1):
            ret = min(ret, minmax(x, a[c+i-1], c+i, f^1))
    d[(c, f)] = ret
    return ret

print(minmax(Z, W, 0, 0))