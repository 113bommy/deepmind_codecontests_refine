def func(x,y):
    return min(x,y)

class SegmentTree:
    def __init__(self, n): #a1, a2, ..., an
        n_ = 1
        while n_ < n:
            n_ *= 2

        self.n = n_
        self.arr = [10**18] * (2*self.n-1)

    def update(self, k, a): #0_indexed
        k += self.n - 1
        self.arr[k] = a

        while k > 0:
            k = (k-1) // 2
            self.arr[k] = min(self.arr[2*k+1], self.arr[2*k+2])

    def query(self, l, r):
        L, R = l+self.n, r+self.n
        ide_ele = float("inf")
        #単位元(ide_ele)は、区間外の値などに設定する値です。
         #ex) 最小値のセグ木 → +inf
         #　和のセグ木 → 0
         #　積のセグ木 → 1
         #  gcdのセグ木 → 0
        res = ide_ele
        while L < R:
            if R & 1:
                R -= 1
                res = func(res, self.arr[R-1]) #

            if L & 1:
                res = func(res, self.arr[L-1])
                L += 1

            L >>= 1
            R >>= 1

        return res

n,m=map(int,input().split())
lrc=[tuple(map(int,input().split())) for _ in range(m)]
dp=SegmentTree(n+1)
dp.update(1,0)

rl=[[] for _ in range(n+1)]
rc=[[] for _ in range(n+1)]
for l,r,c in lrc:
    rl[r].append(l)
    rc[r].append(c)

for r in range(2,n+1):
    x=float("inf")
    for l,c in zip(rl[r],rc[r]):
        y=dp.query(l,r)+c
        if x>y:
            x=y
    dp.update(r,x)
    if r==n:
        ans=x

if ans==float("inf"):
    ans=-1
print(ans)
