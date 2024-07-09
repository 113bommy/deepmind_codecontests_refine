class Multiset:
    def __init__(self, N):
        self.N = N
        self.tree = [0] * (N + 1)
        self.bisect_K = [1 << k for k in reversed(range(N.bit_length()))]

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def __str__(self):
        return "BIT: [{}]".format(
            ", ".join(str(self.sum(i + 1) - self.sum(i))
                      for i in range(self.N))
        )

    def bisect(self, w):
        if w <= 0:
            return 0
        bit, N = self.tree, self.N
        i = 0
        for k in self.bisect_K:
            ni = i + k
            if ni <= N and bit[ni] < w:
                w -= bit[ni]
                i = ni
        return i + 1

    def insert(self, i):
        while i <= self.N:
            self.tree[i] += 1
            i += i & -i

    def erase(self, i):
        while i <= self.N:
            self.tree[i] -= 1
            i += i & -i

    def lower_bound(self, x):
        return self.bisect(self.sum(x))

    def upper_bound(self, x):
        return self.bisect(self.sum(x) + 1)

    def size(self):
        return self.sum(self.N)


def main():

    N, *A = map(int, open(0).read().split())
    B = {a: i for i, a in enumerate(A, 2)}

    ms = Multiset(N + 2)
    ms.insert(1)
    ms.insert(N + 2)

    ans = 0
    for i in range(1, N + 1):
        b = B[i]
        ms.insert(b)
        l = ms.lower_bound(b - 1)
        r = ms.upper_bound(b)
        ans += i * (b - l) * (r - b)

    print(ans)

if __name__ == '__main__':
    main()
