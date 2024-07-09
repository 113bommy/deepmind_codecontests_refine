import sys
from heapq import heappop, heappush


class SegTreeMin:
    """
    以下のクエリを処理する
    1.update:  i番目の値をxに更新する
    2.get_min: 区間[l, r)の最小値を得る
    """

    def __init__(self, n, INF):
        """
        :param n: 要素数
        :param INF: 初期値（入りうる要素より十分に大きな数）
        """
        n2 = 1 << (n - 1).bit_length()
        self.offset = n2
        self.tree = [INF] * (n2 << 1)
        self.INF = INF

    @classmethod
    def from_array(cls, arr, INF):
        ins = cls(len(arr), INF)
        ins.tree[ins.offset:ins.offset + len(arr)] = arr
        for i in range(ins.offset - 1, 0, -1):
            l = i << 1
            r = l + 1
            ins.tree[i] = min(ins.tree[l], ins.tree[r])
        return ins

    def update(self, i, x):
        """
        i番目の値をxに更新
        :param i: index(0-indexed)
        :param x: update value
        """
        i += self.offset
        self.tree[i] = x
        while i > 1:
            y = self.tree[i ^ 1]
            if y <= x:
                break
            i >>= 1
            self.tree[i] = x

    def get_min(self, a, b):
        """
        [a, b)の最小値を得る
        :param a: index(0-indexed)
        :param b: index(0-indexed)
        """
        result = self.INF

        l = a + self.offset
        r = b + self.offset
        while l < r:
            if r & 1:
                result = min(result, self.tree[r - 1])
            if l & 1:
                result = min(result, self.tree[l])
                l += 1
            l >>= 1
            r >>= 1

        return result


n, *ppp = map(int, sys.stdin.buffer.read().split())
INF = 10 ** 18

sgt0 = SegTreeMin.from_array([(p if i % 2 == 0 else INF, i) for i, p in enumerate(ppp)], (INF, -1))
sgt1 = SegTreeMin.from_array([(p if i % 2 == 1 else INF, i) for i, p in enumerate(ppp)], (INF, -1))
sgt = [sgt0, sgt1]
ans = []
heap = []
first_p, i = sgt0.get_min(0, n)
first_q, j = sgt1.get_min(i, n)
heap.append((first_p, first_q, 0, n, i, j))
while heap:
    p, q, l, r, i, j = heappop(heap)
    ans.append(p)
    ans.append(q)
    if l < i:
        k = l % 2
        np, ni = sgt[k].get_min(l, i)
        nq, nj = sgt[k ^ 1].get_min(ni, i)
        heappush(heap, (np, nq, l, i, ni, nj))
    if i + 1 < j:
        k = (i + 1) % 2
        np, ni = sgt[k].get_min(i + 1, j)
        nq, nj = sgt[k ^ 1].get_min(ni, j)
        heappush(heap, (np, nq, i + 1, j, ni, nj))
    if j + 1 < r:
        k = (j + 1) % 2
        np, ni = sgt[k].get_min(j + 1, r)
        nq, nj = sgt[k ^ 1].get_min(ni, r)
        heappush(heap, (np, nq, j + 1, r, ni, nj))

print(*ans)
