import sys

class UnionFind():
    def __init__(self, num, V):
        self.par = [-1]*num
        #self.size = [1]*num
        self.unused = [0]*num
        self.cost = V
    def find(self, x):
        if self.par[x] < 0:
            return x
        else:
            x = self.par[x]
            return self.find(x)
    
    def union(self, x, y):
        rx = self.find(x)
        ry = self.find(y)
        if rx == ry:
            return 0
        if ry > rx:
            rx, ry = ry, rx
        self.par[ry] = rx
        #self.size[rx] += self.size[ry]
        self.cost[rx] += self.cost[ry]
        self.unused[rx] += self.unused[ry]
        self.unused[ry] = 0
        return 1

def solve():
    
    N, M = map(int, input().split())
    X = list(map(int, sys.stdin.readline().split()))
    Edge = [None]*M
    for i in range(M):
        a, b, y = list(map(int, sys.stdin.readline().split()))
        Edge[i] = (y, a-1, b-1)
    
    Edge.sort()
    Tr = UnionFind(N, X)
    for y, a, b in Edge:
        Tr.union(a, b)
        pa = Tr.find(a)
        if Tr.cost[pa] >= y:
            Tr.unused[pa] = 0
        else:
            Tr.unused[pa] += 1
    
    print(sum(Tr.unused))
    return

if __name__ == '__main__':
    solve()