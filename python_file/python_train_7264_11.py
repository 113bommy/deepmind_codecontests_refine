import sys
from bisect import bisect, bisect_left

class SquareDiv(): #区間の最大値を求める
    def __init__(self, N, V):
        k = 1
        while k ** 2 < N: k += 1
        self.array = [V] * k
        self.size = k
        self.indivisual = [V] * N

    def update(self, i, v): #i番目をvに更新する
        self.indivisual[i] = v
        self.array[i // self.size] = max(self.array[i // self.size], v)

    def search(self, left, right): #[left, right]の最大値を求める
        lk, rk = left // self.size, right // self.size
        if lk == rk:
            maxN = 0
            for i in range(left, right + 1): maxN = max(maxN, self.indivisual[i])
            return maxN
        else:
            maxN = self.search(left, (lk + 1) * self.size - 1)
            for k in range(lk + 1, rk): maxN = max(maxN, self.array[k])
            maxN = max(maxN, self.search(rk * self.size, right))
            return maxN

def solve():
    input = sys.stdin.readline
    N = int(input())
    R = [[int(i) for i in input().split()] for _ in range(N)]
    R.sort()
    mod = 998244353
    X = [R[i][0] for i in range(N)]
    Connect = SquareDiv(N, 0)
    DP = dict()
    DP[N] = 1
    for i in reversed(range(N)):
        right = max(i, Connect.search(i, bisect_left(X, sum(R[i])) - 1))
        Connect.update(i, right)
        DP[i] = (DP[right + 1] + DP[i + 1]) % mod
    print(DP[0])
    

    return 0

if __name__ == "__main__":
    solve()
