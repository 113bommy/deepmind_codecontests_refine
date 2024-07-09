import os
import sys
from collections import Counter


class BinaryIndexedTree:
    # http://hos.ac/slides/20140319_bit.pdf
    def __init__(self, size):
        """
        :param int size:
        """
        self._bit = [0] * size
        self._size = size

    def add(self, i, w):
        """
        i 番目に w を加える
        :param int i:
        :param int w:
        """
        x = i + 1
        while x <= self._size:
            self._bit[x - 1] += w
            x += x & -x

    def sum(self, i):
        """
        [0, i) の合計
        :param int i:
        """
        ret = 0
        while i > 0:
            ret += self._bit[i - 1]
            i -= i & -i
        return ret

    def __len__(self):
        return self._size


if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7
# MOD = 998244353

S = sys.stdin.buffer.readline().decode().rstrip()

counter = Counter(S)
# 回文にできるかどうかはかんたんに判定できる
if len(S) % 2 == 0:
    ok = True
    for c, cnt in counter.items():
        ok &= cnt % 2 == 0
else:
    odds = 0
    for c, cnt in counter.items():
        odds += cnt % 2 == 1
    ok = odds == 1
if not ok:
    print(-1)
    exit()

# 左右に寄せる。
# 左側か右側かだけで転倒数を数える
counts = [0] * 26
ls = ''
mid = ''
rs = ''
invs = 0
for c in S:
    n = ord(c) - ord('a')
    counts[n] += 1
    if counter[c] & 1:
        if counts[n] <= counter[c] // 2:
            ls += c
            invs += len(rs) + len(mid)
        elif counts[n] == counter[c] // 2 + 1:
            mid += c
            invs += len(rs)
        else:
            rs += c
    else:
        if counts[n] <= counter[c] // 2:
            ls += c
            invs += len(rs) + len(mid)
        else:
            rs += c

rs = rs[::-1]
# 目的の回文への置換回数と同じ回数で ls -> rs に置換できる
l_idx = [[] for _ in range(26)]
for i, c in enumerate(ls):
    n = ord(c) - ord('a')
    l_idx[n].append(i)
counts = [0] * 26
idx = []
for i, c in enumerate(rs):
    n = ord(c) - ord('a')
    idx.append(l_idx[n][counts[n]])
    counts[n] += 1

# idx を昇順にする == ls と同じ並びにするまでの回数
invs2 = 0
bit = BinaryIndexedTree(size=len(ls))
for i in reversed(idx):
    invs2 += bit.sum(i)
    bit.add(i, 1)
ans = invs + invs2
# print(invs, invs2)
# print(ls, rs)
# print(idx)
print(ans)
