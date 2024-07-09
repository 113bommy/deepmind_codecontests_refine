import sys
input = sys.stdin.readline
N,Q = map(int,input().split())
A = list(map(int,input().split()))
qs = [tuple(map(int,input().split())) for i in range(Q)]

class SegTree:
    def __init__(self,arr,func,unit):
        self.func = func
        self.unit = unit
        n = 1
        while n < len(arr):
            n *= 2
        self.n = n
        nodes = [unit]*(2*n-1)
        nodes[n-1:n-1+len(arr)] = arr
        for i in range(n-2,-1,-1):
            nodes[i] = func(nodes[2*i+1],nodes[2*i+2])
        self.nodes = nodes

    def update(self,i,val):
        i += self.n-1
        self.nodes[i] = val
        while i >= 0:
            i = (i - 1) // 2
            self.nodes[i] = self.func(self.nodes[2*i+1], self.nodes[2*i+2])

    def query(self,l,r):
        l += self.n
        r += self.n
        s = self.unit
        while l < r:
            if r & 1:
                r -= 1
                s = self.func(self.nodes[r-1], s)
            if l & 1:
                s = self.func(s, self.nodes[l-1])
                l += 1
            l >>= 1
            r >>= 1
        return s

INF = float('inf')
segt = SegTree(A, lambda x,y:max(x,y), -INF)

ans = []
for a,b,c in qs:
    if a==1:
        segt.update(b-1,c)
    elif a==2:
        ans.append(segt.query(b-1,c))
    else:
        l = b-1
        r = N
        if segt.query(l,r) < c:
            ans.append(N+1)
        else:
            while r-l > 1:
                m = (l+r)//2
                if segt.query(l,m) >= c:
                    r = m
                else:
                    l = m
            ans.append(r)
print(*ans, sep='\n')