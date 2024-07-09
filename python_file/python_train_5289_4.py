import sys
def solve():
    readline = sys.stdin.readline
    write = sys.stdout.write
    MOD = 998244353

    N = int(readline())
    P = [list(map(int, readline().split())) for i in range(N)]

    P.sort()

    Y = [y for x, y in P]

    def compress(X):
        *XS, = set(X)
        XS.sort()
        return list(map({e: i for i, e in enumerate(XS)}.__getitem__, X))
    Y = compress(Y)

    data = [0]*(N+1)
    def add(k, x):
        while k <= N:
            data[k] += x
            k += k & -k
    def get(k):
        s = 0
        while k:
            s += data[k]
            k -= k & -k
        return s

    def gen(add, get):
        pow2 = [1]*N
        r = 1
        for i in range(1, N):
            pow2[i] = r = r * 2 % MOD

        for i, y in enumerate(Y):
            v1 = get(y+1); v0 = y - v1
            w1 = i - v1; w0 = (N - y - 1) - w1
            add(y+1, 1)
            p1 = pow2[v1]; p0 = pow2[v0]
            q1 = pow2[w1]; q0 = pow2[w0]
            yield (2 * (p1*p0 % MOD)*(q1*q0 % MOD) % MOD) - (1 - p0 - p1 - q0 - q1 + (p0 + q1) * (p1 + q0)) % MOD
    write("%d\n" % (sum(gen(add, get)) % MOD))
solve()