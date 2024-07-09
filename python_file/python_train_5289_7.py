mod = 998244353

class BIT:
    def __init__(self, N):
        self.size = N
        self.tree = [0] * (N + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

N, *XY = map(int, open(0).read().split())
X, Y = XY[::2], XY[1::2]

memo = {y: i for i, y in enumerate(sorted(Y))}
Y = [y for x, y in sorted(zip(X, map(memo.get, Y)), key=lambda p: p[0])]

P = [1]
for i in range(N):
    P.append(P[-1] * 2 % mod)

ans = P[N - 1] * N % mod
bit = BIT(N)
for i, y in enumerate(Y):
    bit.add(y + 1, 1)

    ld = bit.sum(y)
    lu = i - ld

    rd = y - ld
    ru = N - y - 1 - lu

    A, B, C, D = P[ru], P[lu], P[ld], P[rd]

    ans += ((C - 1) * (A - 1) % mod) * (B * D % mod) % mod
    ans += ((B - 1) * (D - 1) % mod) * (C * A % mod) % mod
    ans -= ((C - 1) * (A - 1) % mod) * ((D - 1) * (B - 1) % mod) % mod
    ans %= mod

print(ans)