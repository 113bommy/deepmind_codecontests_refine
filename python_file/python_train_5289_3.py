import sys


class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

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


MOD = 998244353
n = int(input())
xys = []
ys = []
for line in sys.stdin:
    x, y = map(int, line.split())
    xys.append((x, y))
    ys.append(y)
ys.sort()
y_dict = {y: i + 1 for i, y in enumerate(ys)}
xys = [(x, y_dict[y]) for x, y in xys]
xys.sort()
bit = Bit(n)

p2d = [1]
for i in range(n):
    p2d.append(p2d[-1] * 2 % MOD)

ans = 0
for i, (x, y) in enumerate(xys):
    a = bit.sum(y)
    b = i - a
    c = y - a - 1
    d = (n - i - 1) - c
    bit.add(y, 1)
    # print(i, x, y, a, b, c, d)
    pa, pb, pc, pd = p2d[a], p2d[b], p2d[c], p2d[d]
    tmp = p2d[n - 1]
    tmp += (pa - 1) * (pd - 1) * (pb + pc - 1) % MOD
    tmp += (pb - 1) * (pc - 1) % MOD * pa * pd % MOD
    ans = (ans + tmp) % MOD
print(ans)
