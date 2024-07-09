class SegTree:
    """ segment tree with point modification and range product. """
    # # https://yukicoder.me/submissions/452850
    def __init__(self, N, data_f = min, data_unit=1<<30):
        self.N = N
        self.data_f = data_f
        self.data_unit = data_unit
        self.data = [self.data_unit] * (N + N)

    def build(self, raw_data):
        data = self.data
        f = self.data_f
        N = self.N
        data[N:] = raw_data[:]
        for i in range(N - 1, 0, -1):
            data[i] = f(data[i << 1], data[i << 1 | 1])

    def set_val(self, i, x):
        data = self.data
        f = self.data_f
        i += self.N
        data[i] = x
        while i > 1:
            data[i >> 1] = f(data[i], data[i ^ 1])
            i >>= 1

    def fold(self, L, R):
        """ compute for [L, R) """
        vL = vR = self.data_unit
        data = self.data
        f = self.data_f
        L += self.N
        R += self.N
        while L < R:
            if L & 1:
                vL = f(vL, data[L])
                L += 1
            if R & 1:
                R -= 1
                vR = f(data[R], vR)
            L >>= 1
            R >>= 1
        return f(vL, vR)
      
    def search_left(self,f,L,R):
      if not f(self.fold(L,R)): return R
      while R-L>1:
        M = (R+L)//2
        if f(self.fold(L,M)): R = M
        else: L = M
      return L

N,Q=map(int,input().split())
*A,=map(int,input().split())
seg = SegTree(N,max,0)
seg.build(A)
for i in range(Q):
  t,a,b = map(int,input().split())
  if t==1:
    seg.set_val(a-1,b)
  elif t == 2:
    print(seg.fold(a-1,b))
  else:
    print(seg.search_left(lambda x: x >= b,a-1,N)+1)