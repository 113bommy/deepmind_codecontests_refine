import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


### BIT binary
def init(bit, values):
    for i,v in enumerate(values):
        add(bit,i+1,v)
#a1 ~ aiまでの和 O(logn)
def query(bit,i):
    res = 0
    while i > 0:
        res += bit[i]
        i -= i&(-i)
    return res

#ai += x(logN)
def add(bit,i,x):
    if i==0:
        raise RuntimeError
    while i <= len(bit)-1:
        bit[i] += x
        i += i&(-i)
    return

n = int(input())
xy = [tuple(map(int, input().split())) for _ in range(n)]
from bisect import bisect_left
def press(l):
    # xs[inds[i]]==l[i]となる
    xs = sorted(set(l))
    inds = [None] * len(l)
    for i,item in enumerate(l):
        inds[i] = bisect_left(xs, item)
    return xs, inds
_, indx = press([item[0] for item in xy])
_, indy = press([item[1] for item in xy])
xy = list(zip(indx, indy))
xy.sort()
M = 998244353
# ans = (pow(2, n, M) * n) % M
pows = [0]*(n+1)
v = 1
for i in range(n+1):
    pows[i] = v-1
    v *= 2
    v %= M
ans = (pows[n]*n) % M
bit = [0]*(n+1)
for i,(x,y) in enumerate(xy):
    ans -= pows[i] + pows[n-i-1]
    ans += pows[query(bit, y+1)] + pows[i - query(bit, y+1)]
    add(bit, y+1, 1)
    ans %= M
from operator import itemgetter
xy.sort(key=itemgetter(1))
bit = [0]*(n+1)
for i,(x,y) in enumerate(xy):
    ans -= pows[i] + pows[n-i-1]
    ans += pows[i - query(bit, x+1)]
    add(bit, x+1, 1)
    ans %= M
bit = [0]*(n+1)
for i in range(n-1, -1, -1):
    x,y = xy[i]
    ans += pows[(n-1-i) - query(bit, x+1)]
    add(bit, x+1, 1)
    ans %= M
print(ans%M)