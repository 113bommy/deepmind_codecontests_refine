class SegmentTree:
    def __init__(self, N, f, e=None):
        self.N = 1<<(N-1).bit_length()
        self.seg = [e] * (self.N*2)
        self.e = e
        self.f = f

    def build(self, A):
        for i,a in enumerate(A):
            self.seg[i+self.N] = a
        for i in range(self.N-1,0,-1):
            self.seg[i] = self.f(self.seg[i<<1], self.seg[i<<1|1])

    def update(self, i, x): # a_i += x
        i += self.N
        self.seg[i] = x
        while i > 1:
            self.seg[i>>1] = self.f(self.seg[i], self.seg[i^1])
            i >>= 1

    def query(self, a, b): # f [a, b)
        L = R = self.e
        a += self.N
        b += self.N
        while a < b:
            if a&1:
                L = self.f(L, self.seg[a])
                a += 1
            if b&1:
                b -= 1
                R = self.f(self.seg[b], R)
            a >>= 1
            b >>= 1
        return self.f(L, R)

from collections import Counter
def main():
    N,K,*P=map(int, open(0).read().split())
    Mseg=SegmentTree(N, max, 0)
    mseg=SegmentTree(N, min, float("inf"))
    Mseg.build(P)
    mseg.build(P)
    D=Counter(P[:K])
    ans=1
    als=1
    for i in range(1,K):
        als=als+1 if P[i]>P[i-1] else 1
    iss=als==K
    for i in range(N-K):
        als=als+1 if P[i+K]>P[i+K-1] else 1
        mp=mseg.query(i, i+K)
        Mp=Mseg.query(i+1,i+K+1)
        if not (mp==P[i] and Mp==P[i+K]) and not (iss and als==K):
            ans+=1
        iss|=als==K
    print(ans)

if __name__ == "__main__":
    main()