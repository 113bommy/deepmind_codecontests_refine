import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 7)
mod = 10 ** 9 + 7


def count_bit_flag(T):
    T = (T & 0x55555555) + ((T >> 1) & 0x55555555)
    T = (T & 0x33333333) + ((T >> 2) & 0x33333333)
    T = (T & 0x0F0F0F0F) + ((T >> 4) & 0x0F0F0F0F)
    T = (T & 0x00FF00FF) + ((T >> 8) & 0x00FF00FF)
    T = (T & 0x0000FFFF) + ((T >> 16) & 0x0000FFFF)
    return T


def main():
    N = int(input())
    A = tuple(tuple(map(int, input().split())) for _ in range(N))

    memo = {i: set() for i in range(N)}
    for bit in range(1, 1 << N):
        memo[count_bit_flag(bit)-1].add(bit)

    dp = [0] * (1 << N)
    dp[0] = 1
    for i, bit_list in enumerate(memo.values()):
        for bit in bit_list:
            for j, a in enumerate(A[i]):
                if a and (bit >> j) & 1:
                    dp[bit] += dp[bit ^ (1 << j)]
                    dp[bit] %= mod
    print(dp[(1 << N) - 1])


if __name__ == "__main__":
    main()