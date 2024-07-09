class BIT:
    def __init__(self, n):
        self.n = n
        self.tree = [0]*(n+1)

    def update(self, i, v):
        while i <= self.n:
            self.tree[i] += v
            i += i & (-i)

    def query(self, i):
        v = 0
        while i:
            v += self.tree[i]
            i -= i & (-i)
        return v


N, Q = map(int, input().split())
*c, = map(int, input().split())

q = [[] for _ in range(N+1)]
for i in range(Q):
    x, y = map(int, input().split())
    q[y-1].append([i, x-1])

bit = BIT(N)
finds = [-1]*(N+1)
ans = [0]*Q
for i in range(N):
    if finds[c[i]] != -1:
        bit.update(finds[c[i]]+1, -1)

    finds[c[i]] = i
    bit.update(finds[c[i]]+1, 1)

    for j, x in q[i]:
        ans[j] = bit.query(i+1) - bit.query(x)

for a in ans:
    print(a)
