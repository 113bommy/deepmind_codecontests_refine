from itertools import accumulate

class BinaryIndexedTree:
    def __init__(self, As):
        self.numPow2 = 2 ** (len(As)-1).bit_length()
        self.data = [0] * (self.numPow2+1)
        for iA, A in enumerate(As):
            self.addValue(iA, A)

    def addValue(self, iA, A):
        iA += 1
        while iA <= self.numPow2:
            self.data[iA] += A
            iA += iA & -iA

    def getSum(self, iA):
        iA += 1
        ans = 0
        while iA > 0:
            ans += self.data[iA]
            iA -= iA & -iA
        return ans


N, K = map(int, input().split())
As = [int(input()) for _ in range(N)]

Bs = list(accumulate([0]+[A-K for A in As]))
iBs = list(range(N+1))
iBs.sort(key=lambda iB: Bs[iB])

BIT = BinaryIndexedTree([0]*(N+1))

ans = 0
for iB in iBs:
    BIT.addValue(iB, 1)
    ans += BIT.getSum(iB-1)

print(ans)
