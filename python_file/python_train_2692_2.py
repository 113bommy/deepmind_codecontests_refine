import sys
stdin = sys.stdin

sys.setrecursionlimit(10 ** 7)

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x) - 1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())


class UnionFind:
    def __init__(self, node: int) -> None:
        self.n = node
        self.par = [i for i in range(self.n)]
        self.rank = [0 for i in range(self.n)]

    def find(self, x: int) -> int:
        if x == self.par[x]:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def unite(self, x: int, y: int) -> bool:
        if self.isSame(x, y):
            # print("x and y has already united")
            return False

        rx = self.find(x)
        ry = self.find(y)

        if self.rank[rx] < self.rank[ry]:
            self.par[rx] = self.par[ry]
        else:
            self.par[ry] = self.par[rx]

            if self.rank[rx] == self.rank[ry]:
                self.rank[rx] += 1

        return True

    def isSame(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)


from collections import defaultdict

n, k, l = li()

road = [li_() for _ in range(k)]
rail = [li_() for _ in range(l)]

uf_road = UnionFind(n)
uf_rail = UnionFind(n)

for pi, qi in road:
    uf_road.unite(pi, qi)

for ri, si in rail:
    uf_rail.unite(ri, si)

for i in range(n):
    uf_road.find(i)
    uf_rail.find(i)

dic = defaultdict(int)

for road_par, rail_par in zip(uf_road.par, uf_rail.par):
    dic[(road_par, rail_par)] += 1

ans = []
for i in range(n):
    ans.append(dic[(uf_road.par[i], uf_rail.par[i])])

print(*ans)

