class SegTree:
    """ define what you want to do with 0 index, ex) size = tree_size, func = min or max, sta = default_value """
    
    def __init__(self,size,func,sta):
        self.n = size
        self.size = 1 << size.bit_length()
        self.func = func
        self.sta = sta
        self.tree = [sta]*(2*self.size)

    def build(self, list):
        """ set list and update tree"""
        for i,x in enumerate(list,self.size):
            self.tree[i] = x

        for i in range(self.size-1,0,-1):
            self.tree[i] = self.func(self.tree[i<<1],self.tree[i<<1 | 1])

    def set(self,i,x):
        i += self.size
        self.tree[i] = x
        while i > 1:
            i >>= 1
            self.tree[i] = self.func(self.tree[i<<1],self.tree[i<<1 | 1])

    
    def get(self,l,r):
        """ take the value of [l r) with func (min or max)"""
        l += self.size
        r += self.size
        res = self.sta

        while l < r:
            if l & 1:
                res = self.func(self.tree[l],res)
                l += 1
            if r & 1:
                res = self.func(self.tree[r-1],res)
            l >>= 1
            r >>= 1
        return res

n,k = map(int,input().split())
p = list(map(int,input().split()))

segmin = SegTree(n,min,10**18)
segmax = SegTree(n,max,-1)
segmin.build(p)
segmax.build(p)

count = [1]*n
for i in range(1,n):
    if p[i] > p[i-1]:
        count[i] = count[i-1]+1
if n == k or max(count) == n:
    print(1)
    exit()
ans = 1
check = False
if count[k-1] == k:
    check = True
for i in range(k,n):
    if count[i] >= k:
        if check:
            continue
        else:
            check = True
            ans += 1
            continue
    elif segmin.get(i-k,i+1) == p[i-k] and segmax.get(i-k,i+1) == p[i]:
        continue
    ans += 1

print(ans)
    