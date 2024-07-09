class BIT:
    '''https://tjkendev.github.io/procon-library/python/range_query/bit.html'''
    def __init__(self, n):
        self.n = n
        self.data = [0]*(n+1)
        self.el = [0]*(n+1)
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.data[i]
            i -= i & -i
        return s
    def add(self, i, x):
        self.el[i] += x
        while i <= self.n:
            self.data[i] += x
            i += i & -i
    def query(self, i, j=None):
        if j is None:
            return self.el[i]
        return self.sum(j) - self.sum(i)
      
N,Q=map(int,input().split())
*A,=map(int,input().split())
bit = BIT(N)
for i in range(N):
  bit.add(i+1,A[i])
for i in range(Q):
  q,a,b = map(int,input().split())
  if q:
    print(bit.query(a,b))
  else:
    bit.add(a+1,b)