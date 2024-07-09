N = int(input())
S = list(input())
Q = int(input())


class Bit:
    """1-indexed"""

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


en2asc = lambda s: ord(s) - 97

Bits = [Bit(N) for _ in range(26)]
for i, s in enumerate(S):
    Bits[en2asc(s)].add(i + 1, 1)

for _ in range(Q):
    q = input().split()
    if q[0] == '1':
        i, c = int(q[1]), q[2]
        old = S[i - 1]
        Bits[en2asc(old)].add(i, -1)
        Bits[en2asc(c)].add(i, 1)
        S[i - 1] = c
    else:
        l, r = int(q[1]), int(q[2])
        ans = 0
        for b in Bits:
            ans += bool(b.sum(r) - b.sum(l - 1))
        print(ans)
