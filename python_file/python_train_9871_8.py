class SegmentTree:
    def __init__(self, lst, op, e):
        self.n = len(lst)
        self.N = 1 << ((self.n - 1).bit_length())
        self.op = op # operation
        self.e = e # identity element
        self.v = self._build(lst)
        
    def _build(self, lst):
        # construction of a tree
        # total 2 * self.N - 1 elements
        tree = [self.e] * (self.N - 1) + lst + [self.e] * (self.N - self.n)
        for i in range(self.N - 2, -1, -1):
            tree[i] = self.op(tree[2*i + 1], tree[2*i + 2])
        return tree
    
    def __getitem__(self, i):
        return self.v[i + self.N - 1]
    
    # update a_i to be x 
    def update(self, i, x):
        i += self.N - 1
        self.v[i] = x
        while i > 0:
            i -= 1; i >>= 1
            self.v[i] = self.op(self.v[2*i + 1], self.v[2*i + 2])
    
    # returns answer for the query interval [l, r)
    def query(self, l, r):
        left = l + self.N - 1
        right = r + self.N - 1
        L = self.e; R = self.e
        while left < right:
            if left & 1 == 0: # self.v[left] is the right child
                L = self.op(L, self.v[left])
                left += 1
            if right & 1 == 0: # self.v[right-1] is the left child
                right -= 1
                R = self.op(self.v[right], R)
            left -= 1; left >>= 1
            right >>= 1
        return self.op(L, R)

def coord_compress(A):
    B = {a: i for i, a in enumerate(sorted(set(A)))}
    return [B[a] for a in A]
    
N = int(input())
*H, = map(int, input().split())
*A, = map(int, input().split())

H = coord_compress(H)
dp = SegmentTree([0] * len(H), max, 0)
for h, a in zip(H, A):
    dp.update(h, max(dp[h], dp.query(0, h) + a))
print(max(dp))