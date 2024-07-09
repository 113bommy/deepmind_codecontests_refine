import sys
from operator import itemgetter

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


class UnionFind:
    # Reference: https://note.nkmk.me/python-union-find/
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def size(self, x):
        return -self.parents[self.find(x)]

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}


def main():
    N, *XY = map(int, read().split())

    P = [(x, y) for x, y in zip(*[iter(XY)] * 2)]
    uf = UnionFind(N)

    Q = [(x, y, i) for i, (x, y) in enumerate(P)]

    Q.sort()
    for j in range(N - 1):
        if Q[j][0] == Q[j + 1][0]:
            uf.union(Q[j][2], Q[j + 1][2])

    Q.sort(key=itemgetter(1))
    for j in range(N - 1):
        if Q[j][1] == Q[j + 1][1]:
            uf.union(Q[j][2], Q[j + 1][2])

    ans = 0
    for vec in uf.all_group_members().values():
        x_points = len(set(P[i][0] for i in vec))
        y_points = len(set(P[i][1] for i in vec))
        ans += x_points * y_points - len(vec)

    print(ans)
    return


if __name__ == '__main__':
    main()
