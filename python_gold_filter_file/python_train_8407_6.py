class FenwickTree():
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    def build(self, arr):
        #assert len(arr) <= n
        for i, a in enumerate(arr):
            self.data[i] = a
        for i in range(1, self.n + 1):
            if i + (i & -i) <= self.n:
                self.data[i + (i & -i) - 1] += self.data[i - 1]

    def add(self, p, x):
        #assert 0 <= p < self.n
        p += 1
        while p <= self.n:
            self.data[p - 1] += x
            p += p & -p

    def sum(self, r):
        s = 0
        while r:
            s += self.data[r - 1]
            r -= r & -r
        return s

    def range_sum(self, l, r):
        #assert 0 <= l <= r <= self.n
        return self.sum(r) - self.sum(l)

import sys
input = sys.stdin.buffer.readline

N, Q = map(int, input().split())
A = map(int, input().split())

ft = FenwickTree(N)
ft.build(A)
res = []

for _ in range(Q):
    q, x, y = map(int, input().split())
    if q:
        res.append(str(ft.range_sum(x, y)))
    else:
        ft.add(x, y)

print('\n'.join(res))