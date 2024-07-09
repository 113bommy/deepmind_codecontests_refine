class SegTree:
    def __init__(self, N):
        self.N = N
        self._N = 1<<((N-1).bit_length())
        self.node = [10**15]*(2*self._N-1)
        self.node[self._N-1] = 0

    def eval(self,p):
        i = p + self._N-1
        cur = self.node[i]
        while i:
            i = (i-1) // 2
            if cur > self.node[i]:
                cur = self.node[i]
        self.node[p+self._N-1] = cur
        return cur

    def update(self,x,p,q,idx=0,a=0,b=None):
        if not idx:
            x += self.eval(p)
        if x >= 10**15:
            return
        if b is None:
            b = self._N
        if q <= p or b <= p or q <= a:
            return
        elif p <= a and b <= q:
            if x < self.node[idx]:
                self.node[idx] = x
            return
        else:
            self.update(x,p,q,idx*2+1,a,(a+b)//2)
            self.update(x,p,q,idx*2+2,(a+b)//2,b)
            return


n,m = map(int, input().split())
edge = [tuple(map(int, input().split())) for _ in range(m)]
edge.sort()
tr = SegTree(n)
for s,t,c in edge:
    tr.update(c,s-1,t)
ans = tr.eval(n-1)
if ans >= 10**15:
    ans = -1
print(ans)
