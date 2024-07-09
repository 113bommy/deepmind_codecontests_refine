import math
class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
    
    def reset(self):
        t = self.tree
        for i in range(len(t)):
            t[i] = 0

get_ints = lambda: [int(st) for st in input().split()]
N=int(input())
inarr=get_ints()
sorted_in = sorted(inarr)
comb = N*(N+1) // 2

bit = Bit(2*N+1)
def binsearch(lft, rgt):
    half = (lft + rgt) // 2
    if lft >= half:
        return half
    summed = 0
    res = 0
    bit.reset()
    bit.add(N, 1)
    for x in inarr:
        value = 1 if x >= sorted_in[half] else -1
        summed += value
        count = bit.sum(N + summed)
        bit.add(N + summed, 1)
        res += count
    return binsearch(half, rgt) if res >= math.ceil(comb/2) else binsearch(lft, half)

res = binsearch(0, N)
print(sorted_in[res])
