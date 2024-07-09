class BinaryIndexedTree():  #1-indexed
    def __init__(self, n):
        self.n = n
        self.tree = [0 for _ in range(n + 1)]

    def sum(self, index):
        res = 0
        while index:
            res += self.tree[index]
            index -= index & -index
        return res

    def add(self, index, x):
        while index <= self.n:
            self.tree[index] += x
            index += index & -index

    def bisect_left(self, x):
        if x <= 0: return 0
        res, tmp = 0, 2**((self.n).bit_length() - 1)
        while tmp:
            if res + tmp <= self.n and self.tree[res + tmp] < x:
                x -= self.tree[res + tmp]
                res += tmp
            tmp >>= 1
        return res + 1


INF = 10**18

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

res = INF

for i in range(2**N):
    front = []
    back = []
    for j in range(N):
        if (i >> j) & 1:
            front.append((A[j], j))
        else:
            back.append((B[j], j))
    odd = []
    even = []
    for x, j in front:
        if j % 2 == 0:
            odd.append((x, j))
        else:
            even.append((x, j))
    for x, j in back:
        if j % 2 != 0:
            odd.append((x, j))
        else:
            even.append((x, j))
    if len(even) != N // 2:
        continue
    odd.sort()
    even.sort()
    seq = []
    for j in range(N):
        if j % 2 == 0:
            seq.append(odd[j // 2])
        else:
            seq.append(even[j // 2])
    for j in range(N - 1):
        if seq[j][0] > seq[j + 1][0]:
            break
    else:
        bit = BinaryIndexedTree(N)
        count = 0
        for j in range(N):
            bit.add(seq[j][1] + 1, 1)
            count += j + 1 - bit.sum(seq[j][1] + 1)
        res = min(res, count)

print(res if res != INF else -1)