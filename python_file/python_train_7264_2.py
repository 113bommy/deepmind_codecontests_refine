import bisect

LI = lambda: list(map(int, input().split()))

N = int(input())
XD = [LI() for _ in range(N)]

MOD = 998244353


class BIT:

    def __init__(self, n):
        self.n = n
        self.dat = [i - 1 for i in range(self.n + 1)]

    def change(self, i, x):
        i += 1
        while i <= self.n:
            self.dat[i] = max(self.dat[i], x)
            i += i & -i

    def max_num(self, i):
        if i == 0:
            return -1
        return max(self.dat[i], self.max_num(i - (i & -i)))


def main():
    XD.sort()
    x = [None] * N
    d = [None] * N
    for i in range(N):
        x[i], d[i] = XD[i]
    
    bit = BIT(N)
    w = [None] * N
    for i in range(N - 1, -1, -1):
        v = x[i] + d[i]
        j = bit.max_num(bisect.bisect_left(x, v))
        w[i] = j - i
        bit.change(i, j)
    
    dp = [None] * (N + 1)
    dp[-1] = 1
    for i in range(N - 1, -1, -1):
        dp[i] = (dp[i + 1] + dp[i + w[i] + 1]) % MOD
    
    ans = dp[0]
    print(ans)


if __name__ == "__main__":
    main()
