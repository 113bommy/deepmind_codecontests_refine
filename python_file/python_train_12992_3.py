import sys
input = sys.stdin.readline
S = input().rstrip()
T = input().rstrip()

def z_algorithm(s):
    N = len(s)
    ret = [0]*N
    ret[0] = N
    i,j = 1,0
    while i < N:
        while i+j < N and s[j] == s[i+j]:
            j += 1
        ret[i] = j
        if j == 0:
            i += 1
            continue
        k = 1
        while i+k < N and k + ret[k]<j:
            ret[i+k] = ret[k]
            k += 1
        i += k
        j -= k
    return ret

class UnionFind:
    def __init__(self,N):
        self.parent = [i for i in range(N)]
        self._size = [1] * N
        self.count = 0
    def root(self,a):
        if self.parent[a] == a:
            return a
        else:
            self.parent[a] = self.root(self.parent[a])
            return self.parent[a]
    def is_same(self,a,b):
        return self.root(a) == self.root(b)
    def unite(self,a,b):
        ra = self.root(a)
        rb = self.root(b)
        if ra == rb: return
        if self._size[ra] < self._size[rb]: ra,rb = rb,ra
        self._size[ra] += self._size[rb]
        self.parent[rb] = ra
        self.count += 1
    def size(self,a):
        return self._size[self.root(a)]

def solve():
    ls,lt = len(S),len(T)
    ns = 0--(lt+ls)//ls

    za = z_algorithm(T + '#' + S*ns)

    from fractions import gcd
    g = gcd(ls,lt)
    uf = UnionFind(ls)
    match = False
    for i in range(ls):
        if za[lt+1+i] == lt:
            match = True
            j = (i+lt) % ls
            if uf.is_same(i,j):
                if uf.size(i) == ls//g:
                    print(-1)
                    exit()
                continue
            uf.unite(i,j)
    if not match:
        print(0)
        exit()

    ans = 0
    for i in range(ls):
        ans = max(ans, uf.size(i)-1)
    print(ans)

solve()