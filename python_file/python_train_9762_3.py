class MinSegTree:
    """
    0-indexed
    query : [L, R)
    """
    def __init__(self, size):
        self.size = 1 << (size.bit_length())  # 完全二分木にする
        self.data = [INF] * (2 * self.size - 1)

    def build(self, rawData):
        self.data[self.size - 1: self.size - 1 + len(rawData)] = rawData
        for i in range(self.size - 1)[:: -1]:
            self.data[i] = min(self.data[2 * i + 1], self.data[2 * i + 2])

    def update(self, index, value):
        index += self.size - 1
        if self.data[index] <= value:
            return
        self.data[index] = value
        while index >= 0:
            index = (index - 1) // 2
            self.data[index] = min(self.data[2 * index + 1], self.data[2 * index + 2])

    def query(self, left, right):
        L = left + self.size
        R = right + self.size
        ret = INF
        while L < R:
            if R & 1:
                R -= 1
                ret = min(ret, self.data[R - 1])
            if L & 1:
                ret = min(ret, self.data[L - 1])
                L += 1
            L >>= 1
            R >>= 1
        return ret

N, Q = map(int, input().split())
INF = N - 2
treeRow = MinSegTree(N + 2)
treeCol = MinSegTree(N + 2)

miRow = N - 1
miCol = N - 1
ans = (N - 2)**2

for q in range(Q):
    q, x = map(int, input().split())

    if q == 1:
        col = x
        ans -= treeRow.query(col, N)
        miCol = min(col, miCol)
        treeCol.update(miRow, col - 2)
    if q == 2:
        row = x
        ans -= treeCol.query(row, N)
        miRow = min(row, miRow)
        treeRow.update(miCol, row - 2)

print(ans)
