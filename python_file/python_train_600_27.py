import sys
input = sys.stdin.readline
N,M = map(int,input().split())
LRC = [tuple(map(int,input().split())) for i in range(M)]
LRC.sort()

INF = float('inf')
class SegTreeMin:
    def __init__(self,arr):
        n = 1
        while n < len(arr):
            n *= 2
        self.n = n
        nodes = [INF]*(2*n-1)
        nodes[n-1:n-1+len(arr)] = arr
        for i in range(n-2,-1,-1):
            nodes[i] = min(nodes[2*i+1],nodes[2*i+2])
        self.nodes = nodes

    # thanks
    # https://smijake3.hatenablog.com/entry/2018/11/03/100133
    def update(self,i,val):
        i += self.n-1
        self.nodes[i] = val
        while i >= 0:
            i = (i - 1) // 2
            self.nodes[i] = min(self.nodes[2*i+1], self.nodes[2*i+2])

    def query(self,l,r):
        L = l + self.n; R = r + self.n
        s = INF
        while L < R:
            if R & 1:
                R -= 1
                s = min(s, self.nodes[R-1])
            if L & 1:
                s = min(s, self.nodes[L-1])
                L += 1
            L >>= 1; R >>= 1
        return s

segt = SegTreeMin([0] + [INF]*N)
for l,r,c in LRC:
    mn = segt.query(l-1,r-1)
    org = segt.query(r-1,r)
    if org > mn+c:
        segt.update(r-1, mn+c)

ans = segt.query(N-1,N)
print(-1 if ans==INF else ans)