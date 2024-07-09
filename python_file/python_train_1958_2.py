import bisect
import operator
import os
import sys
from collections import defaultdict

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7


class SegmentTree:
    # http://tsutaj.hatenablog.com/entry/2017/03/29/204841
    def __init__(self, size, fn=operator.add, default=None, initial_values=None):
        """
        :param int size:
        :param callable fn: 区間に適用する関数。引数を 2 つ取る。min, max, operator.xor など
        :param default:
        :param list initial_values:
        """
        default = default or 0

        # size 以上である最小の 2 冪を size とする
        n = 1
        while n < size:
            n *= 2
        self._size = n
        self._fn = fn

        self._tree = [default] * (self._size * 2 - 1)
        if initial_values:
            i = self._size - 1
            for v in initial_values:
                self._tree[i] = v
                i += 1
            i = self._size - 2
            while i >= 0:
                self._tree[i] = self._fn(self._tree[i * 2 + 1], self._tree[i * 2 + 2])
                i -= 1

    def set(self, i, value):
        """
        i 番目に value を設定
        :param int i:
        :param value:
        :return:
        """
        x = self._size - 1 + i
        self._tree[x] = value

        while x > 0:
            x = (x - 1) // 2
            self._tree[x] = self._fn(self._tree[x * 2 + 1], self._tree[x * 2 + 2])

    def add(self, i, value):
        """
        もとの i 番目と value に fn を適用したものを i 番目に設定
        :param int i:
        :param value:
        :return:
        """
        x = self._size - 1 + i
        self.set(i, self._fn(self._tree[x], value))

    def get(self, from_i, to_i, k=0, L=None, r=None):
        """
        [from_i, to_i) に fn を適用した結果を返す
        :param int from_i:
        :param int to_i:
        :param int k: self._tree[k] が、[L, r) に fn を適用した結果を持つ
        :param int L:
        :param int r:
        :return:
        """
        L = 0 if L is None else L
        r = self._size if r is None else r

        if from_i <= L and r <= to_i:
            return self._tree[k]

        if to_i <= L or r <= from_i:
            return None

        ret_L = self.get(from_i, to_i, k * 2 + 1, L, (L + r) // 2)
        ret_r = self.get(from_i, to_i, k * 2 + 2, (L + r) // 2, r)
        if ret_L is None:
            return ret_r
        if ret_r is None:
            return ret_L
        return self._fn(ret_L, ret_r)

    def __len__(self):
        return self._size


def eulerian_trail(tree, max_v, root=0):
    """
    木のオイラー路; オイラーツアー
    :param list of (list of (int, int, int)) tree:
    :param int max_v:
    :param int root:
    :return: (trails, depths)
    :rtype: (list of int, list of int, list of (int, int))
    """
    seen = [False] * (max_v + 1)
    # 頂点の履歴
    trails = []
    # 深さの履歴
    depths = []
    # list of (color, weight)
    edges = []
    # Overflow 回避のためループで
    stack = [(root, 0, (0, 0), True)]
    while stack:
        v, d, edge, forward = stack.pop()
        seen[v] = True
        trails.append(v)
        depths.append(d)
        edges.append(edge)
        if not forward:
            continue
        for u, c, w in tree[v]:
            if not seen[u]:
                stack.append((v, d, (c, -w), False))
                stack.append((u, d + 1, (c, w), True))
    return trails, depths, edges


N, Q = list(map(int, sys.stdin.readline().split()))
ABCD = [list(map(int, sys.stdin.readline().split())) for _ in range(N - 1)]
XYVU = [list(map(int, sys.stdin.readline().split())) for _ in range(Q)]

#: :type: list of (list of (int, int, int))
graph = [[] for _ in range(N + 1)]
for a, b, c, d in ABCD:
    graph[a].append((b, c, d))
    graph[b].append((a, c, d))

trails, depths, edges = eulerian_trail(graph, max_v=N, root=1)
ids = [-1] * (N + 1)
for i, t in enumerate(trails):
    ids[t] = i

distances = []
color_dist = defaultdict(lambda: [(-1, 0)])
color_cnt = defaultdict(lambda: [(-1, 0)])
s = 0
for i, (c, d) in enumerate(edges):
    s += d
    distances.append(s)

    color_dist[c].append((i, color_dist[c][-1][1] + d))
    _, cc = color_cnt[c][-1]
    color_cnt[c].append((i, cc + 1 if d > 0 else cc - 1))

st = SegmentTree(size=len(trails), fn=min, default=(IINF, -1), initial_values=list(zip(depths, trails)))


def get_lca(v, u):
    iv, iu = ids[v], ids[u]
    if iv > iu:
        iv, iu = iu, iv
    _, ret = st.get(iv, iu + 1)
    return ret


def distance(v):
    # v から root までの距離
    return distances[ids[v]]


def count_color(v, c):
    # v から root までの c の数
    iv = ids[v]
    i = bisect.bisect_left(color_cnt[c], (iv + 1, 0))
    return color_cnt[c][i - 1][1]


def distance_color(v, c):
    # v から root までの c の数
    iv = ids[v]
    i = bisect.bisect_left(color_dist[c], (iv + 1, 0))
    return color_dist[c][i - 1][1]


for x, y, u, v in XYVU:
    lca = get_lca(u, v)
    d = distance(u) + distance(v) - distance(lca) * 2
    c = count_color(u, x) + count_color(v, x) - count_color(lca, x) * 2
    s = distance_color(u, x) + distance_color(v, x) - distance_color(lca, x) * 2
    print(d - s + c * y)
