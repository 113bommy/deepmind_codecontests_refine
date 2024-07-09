from bisect import bisect_left
from math import sqrt
MOD = 10**9 + 7

def main():
    lim, n = map(int, input().split())
    num, tmp = [], []
    for i in range(1, int(sqrt(lim))+1):
        num.append(i)
        if i**2 != lim:
            tmp.append(lim//i)
    while len(tmp) > 0:
        num.append(tmp.pop(-1))
    m = len(num)
    dp = [[0]*m for _ in range(n)]
    dp[0][0] = 1
    for j in range(1, m):
        dp[0][j] = num[j] - num[j-1]
    for i in range(1, n):
        for j in range(1, m):
            dp[i-1][j] += dp[i-1][j-1]
        for j in range(m):
            idx = bisect_left(num, lim//num[j])
            p = num[j]
            if j > 0:
                p -= num[j-1]
            dp[i][j] = dp[i-1][idx] * p % MOD
    print(sum(dp[-1])%MOD)

if __name__ == "__main__":
    main()