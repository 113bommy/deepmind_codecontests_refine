import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def segfunc(x, y):
    # 求めたい値を算出するためのロジックを書く
    return max(x, y)


class SegmentTree:
    # ide_ele は単位元。初期値
    def __init__(self, init_val, ide_ele):
        self.n = len(init_val)
        self.ide_ele = ide_ele
        self.num = 2 ** (self.n - 1).bit_length()
        self.seg = [self.ide_ele] * 2 * self.num
        for i in range(self.n):
            self.seg[i + self.num - 1] = init_val[i]

        for i in range(self.num - 2, -1, -1):
            self.seg[i] = segfunc(self.seg[2 * i + 1], self.seg[2 * i + 2])

    # 0-indexed
    def update(self, k, x):
        k += self.num - 1
        self.seg[k] = x
        while k:
            k = (k - 1) // 2
            self.seg[k] = segfunc(self.seg[k * 2 + 1], self.seg[k * 2 + 2])

    # 0-indexed
    # 半開区間 pからq - 1 までが担当範囲
    # [p, q)
    def query(self, p, q):
        if q <= p:
            return self.ide_ele
        p += self.num - 1
        q += self.num - 2
        res = self.ide_ele
        while q - p > 1:
            if p & 1 == 0:
                res = segfunc(res, self.seg[p])
            if q & 1 == 1:
                res = segfunc(res, self.seg[q])
                q -= 1
            p = p // 2
            q = (q - 1) // 2
        if p == q:
            res = segfunc(res, self.seg[p])
        else:
            res = segfunc(segfunc(res, self.seg[p]), self.seg[q])
        return res


def main():
    N, K = [int(x) for x in input().split()]
    A = [int(input()) for _ in range(N)]

    init_val = [0] * 300002
    s = SegmentTree(init_val, 0)

    ma = max(A)
    for a in A:
        ans = s.query(max(0, a - K), min(ma, a + K) + 1)
        s.update(a, ans + 1)
    print(s.query(0, ma + 1))


if __name__ == '__main__':
    main()
