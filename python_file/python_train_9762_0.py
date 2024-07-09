class SegTree():
    def __init__(self, initial, operation, identity):
        n = len(initial)
        self.initial = initial
        self.operation = operation
        self.identity = identity
        self.num = 1 << (len(bin(n - 1)) - 2)
        self.tree = [identity] * (2 * self.num - 1)
        for i in range(n):
            self.tree[i + self.num - 1] = self.initial[i]
        for i in reversed(range(self.num - 1)):
            self.tree[i] = min(self.tree[2*i + 1], self.tree[2*i + 2])
    
    def update(self, k, x):
        k += self.num - 1
        self.tree[k] = x
        while k >= 1:
            k = (k - 1) // 2
            self.tree[k] = self.operation(self.tree[2*k + 1], self.tree[2*k + 2])
    
    def query(self, l, r):
        res = self.identity
        l += self.num - 1
        r += self.num - 1
        while l < r:
            if l % 2 == 0:
                res = self.operation(res, self.tree[l])
                l += 1
            if r % 2 == 0:
                res = self.operation(res, self.tree[r - 1])
            l = (l - 1) // 2
            r = (r - 1) // 2
        return res

N, Q = [int(i) for i in input().split()]

H, W = SegTree([N]*N, min, N), SegTree([N]*N, min, N)
revd = 0
for _ in range(Q):
    t, x = [int(i) for i in input().split()]
    if t == 1:
        h = H.query(x, N + 1)
        w = W.query(h, N + 1)
        revd += h - 2
        W.update(h, min(x, w))
    else:
        w = W.query(x, N + 1)
        h = H.query(w, N + 1)
        revd += w - 2
        H.update(w, min(x, h))

ans = (N - 2)*(N - 2) - revd
print(ans)