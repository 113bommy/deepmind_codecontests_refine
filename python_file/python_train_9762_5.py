class SegTree:
    X_unit = 1 << 30
    X_f = min

    def __init__(self, N):
        self.N = N
        self.X = [self.X_unit] * (N + N)

    def build(self, seq):
        for i, x in enumerate(seq, self.N):
            self.X[i] = x
        for i in range(self.N - 1, 0, -1):
            self.X[i] = self.X_f(self.X[i << 1], self.X[i << 1 | 1])

    def set_val(self, i, x):
        i += self.N
        self.X[i] = x
        while i > 1:
            i >>= 1
            self.X[i] = self.X_f(self.X[i << 1], self.X[i << 1 | 1])

    def fold(self, L, R):
        L += self.N
        R += self.N
        vL = self.X_unit
        vR = self.X_unit
        while L < R:
            if L & 1:
                vL = self.X_f(vL, self.X[L])
                L += 1
            if R & 1:
                R -= 1
                vR = self.X_f(self.X[R], vR)
            L >>= 1
            R >>= 1
        return self.X_f(vL, vR)
      
N, Q=map(int,input().split())
S1=SegTree(N)
S2=SegTree(N)

S1.build([N]*N)
S2.build([N]*N)
ans=(N-2)**2

for i in range(Q):
  j, x=map(int,input().split())
  if j==1:
    l=S2.fold(x-1,N)
    ans-=l-2
    S1.set_val(l-1,min(x,S1.X[l-1+N]))
  if j==2:
    l=S1.fold(x-1,N)
    ans-=l-2
    S2.set_val(l-1,min(x,S2.X[l-1+N]))
    
print(ans)