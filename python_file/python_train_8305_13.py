n = int(input())
p = [(int(x), i) for i, x in enumerate(input().split())]
p.sort(reverse=True)

class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.data = [0] * (self.n+1)
    
    def sum(self, i):
        res = 0
        while i > 0:
            res += self.data[i]
            i -= i & -i
        return res
    
    def add(self, i, x):
        if i <= 0: return
        while i <= self.n:
            self.data[i] += x
            i += i & -i
    
    def lower_bound(self, x):
        if x <= 0: return 0
        cur, s, k = 0, 0, 1 << (self.n.bit_length()-1)
        while k:
            nxt = cur + k 
            if nxt <= self.n and s + self.data[nxt] < x:
                s += self.data[nxt]
                cur = nxt
            k >>= 1
        return cur + 1

bit = BinaryIndexedTree(n)
ans = 0

for x, i in p:
    i += 1
    bit.add(i, 1)
    idx = bit.sum(i)
    l1, l2 = bit.lower_bound(idx-1), bit.lower_bound(idx-2)
    r1, r2 = bit.lower_bound(idx+1), bit.lower_bound(idx+2)
    ans += ((l1-l2) * (r1-i) + (i-l1) * (r2-r1)) * x

print(ans)
