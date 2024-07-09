import sys

readline = sys.stdin.readline
readall = sys.stdin.read
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prn = lambda x: print(*x, sep='\n')

def popcount(x):
    x = x - ((x >> 1) & 0x55555555)
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f
    x = x + (x >> 8)
    x = x + (x >> 16)
    return x & 0x0000007f


def solve():
    n, k, s, t = nm()
    a = [x ^ s for x in nl() if x & s == s and x | t == t]
    n = len(a)
    t ^= s
    s = 0
    C = [[0]*(n+1) for i in range(n+1)]
    for i in range(n+1):
        for j in range(i+1):
            if j == 0:
                C[i][j] = 1
            elif i > 0:
                C[i][j] = C[i-1][j] + C[i-1][j-1]
    D = [0]*(n+1)
    for i in range(n+1):
        for j in range(1, min(k, n)+1):
            D[i] += C[i][j]
    for i in range(n, 0, -1):
        D[i] -= D[i-1]
    l = list()
    for i in range(20, -1, -1):
        if t & (1 << i):
            l.append(i)
    p = len(l)
    na = list()
    for x in a:
        v = 0
        for i in l:
            v = v << 1 | x >> i & 1
        na.append(v)
    pc = [popcount(i) for i in range(1 << p)]
    l = [0]*(1 << p)
    ans = 0
    for bit in range(1 << p):
        cur = 0
        for x in na:
            l[bit&x] += 1
            cur += D[l[bit&x]]
        for x in na:
            l[bit&x] -= 1
        if pc[bit] & 1:
            ans -= cur
        else:
            ans += cur
    print(ans)
    return

solve()
