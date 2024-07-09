import sys
from collections import Counter
from bisect import bisect_left

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

class BitSum:
    def __init__(self, n):
        self.n = n
        self.table = [0] * (n + 1)

    def update(self, i, x):
        i += 1
        while i <= self.n:
            self.table[i] += x
            i += i & -i

    def sum(self, i):
        i += 1
        res = 0
        while i > 0:
            res += self.table[i]
            i -= i & -i
        return res

def main():
    n = int(input())
    aa = list(map(int, input().split()))
    aa = list(Counter(aa).values())
    aa.sort()
    bit = BitSum(len(aa))
    for i, a in enumerate(aa):
        bit.update(i, a)
    # print(aa)
    for k in range(1, n + 1):
        l = 0
        r = n // k + 2
        while l + 1 < r:
            m = (l + r) // 2
            i = bisect_left(aa, m)
            s = bit.sum(i - 1) + m * (len(aa) - i)
            if s >= m * k:
                l = m
            else:
                r = m
        print(l)

main()
