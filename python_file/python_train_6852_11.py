class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0]*(n+1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            #i & -iでLSB(least significant bit/最下位 bit)が求まる
            #区間和はLSBだけ引いていく
            i -= i & -i
        return s

    #a_i(1<=i<=n)にxを加算
    #点に対する更新
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

def invnumber(n, S):
    bit = Bit(2*n+1)
    invs = 0
    for i in range(n):
        s = S[i]+n #BITで扱うため
        invs += bit.sum(s) # #i<j
        bit.add(s, 1)
    return invs

n = int(input())
a = list(map(int, input().split()))
r = max(a)+1
l = 0
c = (n*(n+1)//2+1)//2
while r-l > 1:
    m = (l+r)//2
    S = [0]*(n+1)
    for i in range(1, n+1):
        if a[i-1] >= m:
            S[i] = S[i-1] + 1
        else:
            S[i] = S[i-1] - 1
    if invnumber(n+1, S) >= c:
        l = m
    else:
        r = m
print(l)
